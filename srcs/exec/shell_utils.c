/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:30:49 by noam              #+#    #+#             */
/*   Updated: 2024/11/27 17:16:11 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	close_fd(int fd)
{
	if (fd > 0)
	{
		close(fd);
		fd = -1;
	}
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

void	init_shell(t_shell *shell, char **envp)
{
	shell->start = NULL;
	shell->env = get_env(envp);
	shell->in = dup(STDIN);
	shell->out = dup(STDOUT);
	shell->fdin = 0;
	shell->fdout = 0;
	shell->pipin = -1;
	shell->pipout = -1;
	shell->pid = 0;
	shell->charge = 0;
	shell->parent = 0;
	shell->exec = 1;
}