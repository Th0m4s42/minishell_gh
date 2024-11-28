/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_n_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:12:07 by noam              #+#    #+#             */
/*   Updated: 2024/11/21 22:15:29 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

/* ************************************************************************** */

int		pipe_n_fork(t_shell *shell)
{
	int		pipefd[2];
	int		pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		shell->pipin = pipefd[0];
		shell->parent = 0;
		shell->pid = -1;
		return (2);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		shell->pipout = pipefd[1];
		shell->pid = pid;
		return (1);
	}
}

/* ************************************************************************** */
