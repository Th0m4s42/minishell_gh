/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:37 by noam              #+#    #+#             */
/*   Updated: 2024/11/06 15:32:42 by noam             ###   ########.fr       */
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

# define	CMD 0
# define	CMD_PATH 1
# define	ARG 2
# define	PIPE 3
# define	IN 4
# define	HERE_DOC 5
# define	APPEND 6
# define	TRUNC 7


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


/* ************************************************************************** */

t_token		next_sep(t_token *token);
t_token		prev_sep(t_token *token);


#endif