/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:30:49 by noam              #+#    #+#             */
/*   Updated: 2024/12/06 01:01:05 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

bool	close_fd(int fd)
{
	if (fd > 0)
	{
		close(fd);
		return (true);
	}
	else
		return (false);
}

void	close_reset_fd(t_shell *shell)
{
	close_fd(shell->fdin);
	close_fd(shell->fdout);
	close_fd(shell->pipin);
	close_fd(shell->pipout);
	shell->fdin = -1;
	shell->fdout = -1;
	shell->pipin = -1;
	shell->pipout = -1;
}

void	reset_stds(t_shell *shell)
{
	dup2(shell->in, STDIN);
	dup2(shell->out, STDOUT);
	close(shell->in);
	close(shell->out);
	shell->in = -1;
	shell->out = -1;
}

