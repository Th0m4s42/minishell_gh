/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/12/18 11:50:57 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
// #include <libft.h>

/* ************************************************************************** */

char	**format_cmd(t_token *cmd_tok)
{
	char		**format_cmd;
	char		*tmp_str;
	t_token		*tok;

	tmp_str = ft_strjoin(cmd_tok->value, "\\");
	tok = cmd_tok->next;
	while (tok && tok->type == ARG)
	{
		tmp_str = ft_strjoin_free(tmp_str, tok->value, 1);
		tmp_str = ft_strjoin_free(tmp_str, "\\", 1);
		tok = tok->next;
	}
	format_cmd = ft_split(tmp_str, '\\');
	free(tmp_str);
	return (format_cmd);
}

/* ************************************************************************** */

void	exec_cmd(t_shell *shell, t_token *token)
{
	char	**cmd;
	// int		i;

	cmd = format_cmd(token);
	// i = 0;
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


// void	print_shell(t_shell *shell)
// {
// 	fprintf(stderr, "in: %d\n", shell->in);
// 	fprintf(stderr, "out: %d\n", shell->out);
// 	fprintf(stderr, "fdin: %d\n", shell->fdin);
// 	fprintf(stderr, "fdout: %d\n", shell->fdout);
// 	fprintf(stderr, "pipin: %d\n", shell->pipin);
// 	fprintf(stderr, "pipout: %d\n", shell->pipout);
// 	fprintf(stderr, "pid: %d\n", shell->pid);
// 	fprintf(stderr, "charge: %d\n", shell->charge);
// 	fprintf(stderr, "parent: %d\n", shell->parent);
// 	// fprintf(stderr, "last: %d\n", shell->last);
// 	fprintf(stderr, "exec: %d\n", shell->exec);
// }
/* ************************************************************************** */

void	redir_and_exec(t_shell *shell, t_token *token)
{
	t_token	*next;
	t_token	*prev;
	int		pipe;

	next = next_sep(token);
	prev = prev_sep(token);
	// if (prev)
	// 	fprintf(stderr, "prev---- %s\n", prev->value);
	// if (next)
	// 	fprintf(stderr, "next++++ %s\n", next->value);
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
	if (next && next->type != END && pipe !=1)
		redir_and_exec(shell, next);
						// fprintf(stderr, "\033[0;36m");

		// print_shell(shell);
		// fprintf(stderr, "the token issss === %s", token->value);
		// fprintf(stderr, "%d\n", token->type);
		// fprintf(stderr, "\033[0m");
	if ((!prev || prev->type == PIPE || token->type == CMD || token->type == CMD_PATH)
			&& (token->type == CMD_PATH || token->type == CMD ) && pipe != 1 && shell->exec && shell->charge)
		{
					// fprintf(stderr, "\033[0;35m");

		// print_shell(shell);
		// fprintf(stderr, "the token is === %s\n", token->value);
		// fprintf(stderr, "\033[0m");


		exec_cmd(shell, token);
		}
	return ;
}

/* ************************************************************************** */



void	exec(t_shell *shell)
{
	t_token	*token;
	int		status;
	int		current_doc_nb;
	static int	doc_nb;

	token = shell->start;
	current_doc_nb = doc_nb;
	token = handle_here_docs(token, shell->env, &doc_nb);
	// while (shell->exec && token)
	// {
		shell->parent = 1;
		shell->charge = 1;
		redir_and_exec(shell, token);
		reset_stds(shell);
		close_reset_fd(shell);
		waitpid(shell->pid, &status, 0);
		if (shell->charge == 0 && shell->parent == 0)
			exit(0);
	// fprintf(stderr ,"nb doc = %d-\n", doc_nb);
		del_docs(&doc_nb, current_doc_nb);
		// we should be catching the last child status here but idk how yet
	// }
}
