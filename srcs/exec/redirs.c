/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:20:41 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 00:15:58 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <errno.h>

/* ************************************************************************** */

void	input(t_shell *shell, t_token *token)
{
	if (close_fd(shell->fdin))
		shell->fdin = -1;
	shell->fdin = open(token->value, O_RDONLY);
	if (shell->fdin == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		perror(token->value);
		return ;
	}
	dup2(shell->fdin, STDIN);
}

/* ************************************************************************** */

void	redir(t_shell *shell, t_token *token, t_token_type type)
{
	close_fd(shell->fdout);
	if (type == TRUNC)
		shell->fdout = open(token->value, O_CREAT | O_WRONLY
				| O_TRUNC, S_IRWXU);
	else
		shell->fdout = open(token->value, O_CREAT | O_WRONLY
				| O_APPEND, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		perror(token->value);
		return ;
	}
	dup2(shell->fdout, STDOUT);
}

/* ************************************************************************** */

static int	parent_process(t_shell *shell, int pipefd[2], int pid, int dev_null)
{
	close(pipefd[0]);
	if (shell->fdout < 1)
		dup2(pipefd[1], STDOUT);
	close(pipefd[1]);
	if (shell->fdin < 1 && shell->parent)
		dup2(dev_null, STDIN_FILENO);
	shell->pipout = pipefd[1];
	shell->pid = pid;
	shell->last = 0;
	return (1);
}

/* ************************************************************************** */

static int	child_process(t_shell *shell, int pipefd[2])
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN);
	close(pipefd[0]);
	shell->pipin = pipefd[0];
	shell->parent = 0;
	shell->pid = -1;
	return (2);
}

/* ************************************************************************** */

int	pipe_n_fork(t_shell *shell)
{
	int		pipefd[2];
	int		pid;
	int		dev_null;

	dev_null = open("/dev/null", O_RDONLY);
	if (pipe(pipefd))
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
		return (child_process(shell, pipefd));
	else
		return (parent_process(shell, pipefd, pid, dev_null));
}

/* ************************************************************************** */
