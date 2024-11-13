/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/11/06 15:31:08 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	redir_and_exec(t_shell *shell, t_token *token)
{
	t_token	next;
	t_token	prev;
	int	pipe;

	next = next_sep(token);
	prev = prev_sep(token);
	if ()
}

void	exec(t_shell *shell)
{
	t_token *token;

	token = shell->start;
	while (shell->exec && token)
	{
		// shell->charge = 1;
		shell->parent = 1;
		shell->last = 1;
		redir_and_exec(shell, token);
	}
}