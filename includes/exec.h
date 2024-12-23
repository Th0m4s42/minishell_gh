/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:37 by noam              #+#    #+#             */
/*   Updated: 2024/12/23 01:30:28 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H


# include <minishell.h>
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
#include <limits.h>


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
	t_env			*fallback_env; 
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
	// int				exit;
	int				exec;
	int				ret;
	char			*hiddn_pwd;
	char			*hiddn_oldpwd;
	
}				t_shell;


/* ******-LIBFT + *********************************************************** */

char		*ft_strjoin_free(char *s1, char *s2, int free_ss);
bool		has_backslash(char *str);
bool		eradicate_quotes(char *str);

/* ******-INIT************************************************************** */

t_token		*add_end_tok(t_token *toks);
void		init_shell(t_shell *shell, char **envp);
void		exec(t_shell *shell);

/* ******-NODE*************************************************************** */

int			is_type(t_token *token, t_token_type type);
t_token		*next_sep(t_token *token);
t_token		*prev_sep(t_token *token);

/* ******-DOC N $VAR********************************************************* */

t_token		*handle_here_docs(t_token *token, t_env *env, int *doc_nb);

bool		has_dolla_sign(char *str);
int			until_dolla_sign(char *str, int i);
char		*replace_dolla_sign(char *str, t_env *env);
int			until_space(char *str, int i);

void		del_docs(int *doc_nb, int doc_from_parent);

/* ******-REDIR N EXEC****************************************************** */

void		redir(t_shell *shell, t_token *token, t_token_type type);
void		input(t_shell *shell, t_token *token);
int			pipe_n_fork(t_shell *shell);

int		exec_bin(char **cmd_arg, t_env *env);

/* ******-FDs STDs CLEANUP************************************************** */

bool		close_fd(int fd);
void		close_reset_fd(t_shell *shell);
void		reset_stds(t_shell *shell);

/* ******-BUILT INS********************************************************* */

bool		is_built_in(char *cmd);
int			exec_built_in(char **cmd_arg, t_env *env, t_shell *shell);
int			ft_echo(char **cmd_arg, t_shell *shell);
int			ft_cd(char **cmd, t_shell *shell);
int			ft_pwd(void);
int			ft_export(char **cmd, t_shell *shell);
int			ft_unset(char **cmd_arg, t_shell *shell);
int			ft_env(t_env *env);
int			ft_exit(char **cmd_arg, t_shell *shell);

/* ******-******************************************************************* */

bool		already_set(t_env *env, char *name, int len, char *var_value);
void	 	add_in_lex_order(t_env **first, t_env *new_var);
void	set_var(t_env **env, char *name, char *value, int exp_env);




/* ************************************************************************** */


#endif

