/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:37 by noam              #+#    #+#             */
/*   Updated: 2024/11/06 15:16:40 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

// # include <fcntl.h>
# include "env.h"
# include "lexer.h"


# define STDIN 0
# define STDOUT 1
# define STDERR 2


/* ************************************************************************** */

typedef struct	s_shell
{
	t_token			*start;
	t_env			*env;
	// t_env			*secret_env;
	int				in;
	int				out;
	int				fdin;
	int				fdout;
	int				pipin;
	int				pipout;
	int				pid;
	// int				charge;
	int				parent;
	int				last;
	// int				ret;
	// int				exit;
	int				exec;
}				t_shell;


#endif