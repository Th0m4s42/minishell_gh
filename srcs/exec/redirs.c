/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:20:41 by noam              #+#    #+#             */
/*   Updated: 2024/11/14 16:13:41 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <errno.h>

void	redir(t_shell *shell, t_token *token, int type)
{
	int	err;

	err = 0;
	ft_close(shell->fdout);
	if (type == TRUNC)
		shell->fdout = open(token->value, O_CREAT | O_WRONLY
				| O_TRUNC, S_IRWXU);
	else
		shell->fdout = open(token->value, O_CREAT | O_WRONLY
				| O_APPEND, S_IRWXU);
	if (shell->fdout == -1)
	{
		err = errno;
		ft_putstr_fd("minishell : ", STDERR);
		strerror(err);
		// write (STDERR, "minishell : ", 12);
		// ft_putvalue_fd(token->value, STDERR);
		// ft_putendl_fd(": No such file or directory", STDERR);
		// shell->ret = 1;
		// shell->no_exec = 1;
		return ;
	}
	dup2(shell->fdout, STDOUT);
}

