/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:20:41 by noam              #+#    #+#             */
/*   Updated: 2024/11/27 17:41:04 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <errno.h>

void	input(t_shell *shell, t_token *token)
{
	close_fd(shell->fdin);
	shell->fdin = open(token->value, O_RDONLY);
	if (shell->fdin == -1)
	{
		ft_putstr_fd("minishell : ", STDERR);
		ft_putstr_fd(token->value, STDERR);
		strerror(errno);
		return ;
	}
	dup2(shell->fdin, STDIN);
}

void	redir(t_shell *shell, t_token *token, t_token_type type)
{
	fprintf(stderr, "redir\n");
	close_fd(shell->fdout);
	if (type == TRUNC)
		shell->fdout = open(token->value, O_CREAT | O_WRONLY
				| O_TRUNC, S_IRWXU);
	else
		shell->fdout = open(token->value, O_CREAT | O_WRONLY
				| O_APPEND, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd("minishell : ", STDERR);
		ft_putstr_fd(token->value, STDERR);
		strerror(errno);
		// write (STDERR, "minishell : ", 12);
		// ft_putendl_fd(": No such file or directory", STDERR);
		// shell->ret = 1;
		// shell->no_exec = 1;
		return ;
	}
	dup2(shell->fdout, STDOUT);
}

