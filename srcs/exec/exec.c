/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/12/23 15:16:55 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

char	**format_cmd(t_token *cmd_tok)
{
	char		**format_cmd;
	t_token		*tok;
	int			tab_len;
	int			i;

	i = 0;
	tab_len = 0;
	tok = cmd_tok;
	if (!tok->value)
		return (NULL);
	while (tok && (tok->type == ARG || !tab_len))
	{
		tab_len++;
		tok = tok->next;
	}
	format_cmd = (char **)malloc(sizeof(char *) * (tab_len + 1));
	tok = cmd_tok;
	while (tok && (tok->type == ARG || i == 0))
	{
		if (tok->value)
			format_cmd[i] = ft_strdup(tok->value);
		else
			format_cmd[i] = ft_strdup("\0");
		i++;
		tok = tok->next;
	}
	format_cmd[i] = NULL;
	return (format_cmd);
}

/* ************************************************************************** */

void	exec_cmd(t_shell *shell, t_token *token)
{
	char	**cmd;

	cmd = format_cmd(token);
	if (cmd && is_built_in(cmd[0]))
		exec_built_in(cmd, shell->env, shell);
	else if (cmd)
		exec_bin(cmd, shell->env);
	ft_free_tab(cmd);
	close_fd(shell->pipin);
	close_fd(shell->pipout);
	shell->pipin = -1;
	shell->pipout = -1;
	shell->charge = 0;
}

/* ************************************************************************** */

void	redir_and_exec(t_shell *shell, t_token *token)
{
	t_token	*next;
	t_token	*prev;
	int		pipe;

	next = next_sep(token);
	prev = prev_sep(token);
	pipe = 0;
	if (is_type(prev, TRUNC))
		redir(shell, prev, TRUNC);
	else if (is_type(prev, APPEND))
		redir(shell, prev, APPEND);
	else if (is_type(prev, IN))
		input(shell, prev);
	else if (is_type(prev, HERE_DOC))
		input(shell, prev);
	else if (is_type(token, PIPE))
		pipe = pipe_n_fork(shell);
	if (next && next->type != END && pipe != 1)
		redir_and_exec(shell, next);
	if ((!prev || prev->type == PIPE || token->type == CMD
			|| token->type == CMD_PATH) && (token->type == CMD_PATH
			|| token->type == CMD) && pipe != 1 && shell->exec && shell->charge)
		exec_cmd(shell, token);
	return ;
}

/* ************************************************************************** */

void	exec(t_shell *shell)
{
	t_token		*token;
	int			status;
	int			current_doc_nb;
	static int	doc_nb;

	token = shell->start;
	current_doc_nb = doc_nb;
	signal(SIGINT, ft_handle_sigint_doc);
	token = handle_here_docs(token, shell->env, &doc_nb);
	signal(SIGINT, ft_handle_sigint_child);
	// current_doc_nb = doc_nb;
	shell->parent = 1;
	shell->charge = 1;
	redir_and_exec(shell, token);
	reset_stds(shell);
	close_reset_fd(shell);
	waitpid(shell->pid, &status, 0);
	if (shell->charge == 0 && shell->parent == 0)
		exit (0);
	del_docs(&doc_nb, current_doc_nb);
}
