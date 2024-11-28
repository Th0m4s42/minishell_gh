/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:37 by noam              #+#    #+#             */
/*   Updated: 2024/11/27 17:44:48 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H


# include "minishell.h"
// # include "env.h"
// # include <libft.h>
// # include "lexer.h"
// # include "stdio.h"
# include <fcntl.h>
// # include <stdbool.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>


# define STDIN 0
# define STDOUT 1
# define STDERR 2

// # define CMD 0
// # define CMD_PATH 1
// # define ARG 2
// # define PIPE 3
// # define IN 4
// # define HERE_DOC 5
// # define APPEND 6
// # define TRUNC 7
// # define END 8


# define	REDIRECTION 0
# define	IN 1
# define	HERE_DOC 2
# define	TRUNC 3
# define	APPEND 4
# define	PIPE 5
# define	CMD_PATH 6
# define	CMD 7
# define	ARG 8
# define	END 9




// typedef enum s_token_type
// {
// 	REDIRECTION_,
// 	INFILE_,
// 	HEREDOC_,
// 	APPEND_,
// 	OUTFILE_,
// 	PIPE_,
// 	CMD_PATH_,
// 	CMD_,
// 	ARG_
// }	t_token_type;

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

// typedef struct s_token
// {
// 	struct s_token	*prev;
// 	char			*value;
// 	t_token_type	type;
// 	struct s_token	*next;
// }	t_token;









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
	int				charge;
	int				parent;
	// int				last;
	// int				ret;
	// int				exit;
	int				exec;
}				t_shell;


/* ************************************************************************** */

void		exec(t_shell *shell);

t_token		*next_sep(t_token *token);
t_token		*prev_sep(t_token *token);

int			is_type(t_token *token, t_token_type type);

void		handle_here_docs(t_token *token, t_env *env);

int			until_dolla_sign(char *str, int i);
bool		has_dolla_sign(char *str);
char		*replace_dolla_sign(char *str, t_env *env);

void		redir(t_shell *shell, t_token *token, t_token_type type);
int			pipe_n_fork(t_shell *shell);
void		input(t_shell *shell, t_token *token);

void		close_fd(int fd);
void		close_reset_fd(t_shell *shell);
void		reset_stds(t_shell *shell);
void		init_shell(t_shell *shell, char **envp);

void		exec_bin(char **cmd_arg, t_env *env);

/* ************************************************************************** */


#endif