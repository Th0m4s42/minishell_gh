/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:37 by noam              #+#    #+#             */
/*   Updated: 2024/11/14 16:32:13 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H


# include "env.h"
# include "lexer.h"
# include "stdio.h"
# include <fcntl.h>
# include <stdbool.h>


# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define CMD 0
# define CMD_PATH 1
# define ARG 2
# define PIPE 3
# define IN 4
# define HERE_DOC 5
# define APPEND 6
# define TRUNC 7
# define END 8


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
	// int				pipin;
	// int				pipout;
	int				pid;
	// int				charge;
	int				parent;
	// int				last;
	// int				ret;
	// int				exit;
	int				exec;
}				t_shell;


/* ************************************************************************** */

t_token		*next_sep(t_token *token);
t_token		*prev_sep(t_token *token);

int			is_type(t_token *token, int type);

void		handle_here_docs(t_token *token, t_env *env);

int			until_dolla_sign(char *str, int i);
bool		has_dolla_sign(char *str);
char		*replace_dolla_sign(char *str, t_env *env);

void		redir(t_shell *shell, t_token *token, int type);

#endif