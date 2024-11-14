/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/11/14 16:37:07 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	redir_and_exec(t_shell *shell, t_token *token)
{
	t_token	*next;
	t_token	*prev;
	int		pipe;

	next = next_sep(token);
	prev = prev_sep(token);
	if (is_type(prev, TRUNC))
		redir(shell, token, TRUNC);
	else if (is_type(prev, APPEND))
		redir(shell, token, APPEND);
	else if (is_type(prev, IN))
		input(shell, token);
	else if (is_type(prev, HERE_DOC))
		input(shell, token);
	else if (is_type(prev, PIPE))
		pipe_n_fork(shell, token);
	if (next && next->type != END && pipe !=1)
		redir_and_exec(shell, next);
	if ((prev->type == END || prev->type == PIPE || !prev)
		&& pipe != 1 && shell->exec)
		return ;
		// exec_cmd(shell, token);
}

void	exec(t_shell *shell)
{
	t_token	*token;

	token = shell->start;
	handle_here_docs(&token, shell->env);
	while (shell->exec && token)
	{
		shell->parent = 1;
		redir_and_exec(shell, token);
	}
}
