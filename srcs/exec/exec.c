/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/12/25 16:19:08 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

void	exec_cmd(t_shell *shell, t_token *token)
{
	char	**cmd;

	cmd = format_cmd(token);
	if (cmd && is_built_in(cmd[0]))
		shell->ret = exec_built_in(cmd, shell->env, shell);
	else if (cmd)
		shell->ret = exec_bin(cmd, shell->env);
	ft_free_tab(cmd);
	close_fd(shell->pipin);
	close_fd(shell->pipout);
	shell->pipin = -1;
	shell->pipout = -1;
	shell->charge = 0;
}

/* ************************************************************************** */

void	handle_wait_status(t_shell *shell, int *status)
{
	if (shell->last)
		waitpid(0, status, 0);
	else
	{
		waitpid(shell->pid, status, 0);
		if (WIFEXITED(*status))
			shell->ret = WEXITSTATUS(*status);
		else if (WIFSIGNALED(*status))
			shell->ret = 128 + WTERMSIG(*status);
		else
			shell->ret = *status;
	}
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

void	prep_exec(t_shell *shell, t_token **tok, int *currdoc_nb, int *doc_nb)
{
	*tok = shell->start;
	*currdoc_nb = *doc_nb;
	g_lobal_exit_code = 0;
	signal(SIGINT, ft_handle_sigint_doc);
	*tok = handle_here_docs(*tok, shell->env, doc_nb);
	signal(SIGINT, ft_handle_sigint_child);
	if (g_lobal_exit_code == 2)
	{
		del_docs(doc_nb, *currdoc_nb);
		shell->ret = 130;
		return ;
	}
	shell->last = 1;
	shell->parent = 1;
	shell->charge = 1;
}

/* ************************************************************************** */

void	exec(t_shell *shell)
{
	t_token		*token;
	int			status;
	static int	doc_nb;
	int			current_doc_nb;

	prep_exec(shell, &token, &current_doc_nb, &doc_nb);
	redir_and_exec(shell, token);
	reset_stds(shell);
	close_reset_fd(shell);
	handle_wait_status(shell, &status);
	if (shell->charge == 0 && shell->parent == 0)
		exit(shell->ret);
	del_docs(&doc_nb, current_doc_nb);
}
