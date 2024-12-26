/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:37 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 02:27:18 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <minishell.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define REDIRECTION 0
# define IN 1
# define HERE_DOC 2
# define TRUNC 3
# define APPEND 4
# define PIPE 5
# define CMD_PATH 6
# define CMD 7
# define ARG 8
# define END 9

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_shell
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
	int				exec;
	int				last;
	// int pipe_pid[2];
	int				ret;
	char			*hiddn_pwd;
	char			*hiddn_oldpwd;

}				t_shell;

/* ******-LIBFT + *********************************************************** */

char		*ft_strjoin_free(char *s1, char *s2, int free_ss);
bool		has_backslash(char *str);
bool		eradicate_quotes(char *str);
bool		isnt_alnum(char *str);

/* ******-INIT************************************************************** */

t_token		*add_end_tok(t_token *toks);
void		init_shell(t_shell *shell, char **envp);
void		exec(t_shell *shell);

/* ******-NODE*************************************************************** */

int			is_type(t_token *token, t_token_type type);
t_token		*next_sep(t_token *token);
t_token		*prev_sep(t_token *token);

/* ******-DOC N $VAR********************************************************* */

t_token		*handle_here_docs(t_token *token, t_shell *shell, int *doc_nb);

bool		has_dolla_sign(char *str);
int			until_dolla_sign(char *str, int i);
char		*replace_dolla_sign(char *str, t_shell *shell);
int			until_space(char *str, int i);

void		del_docs(int *doc_nb, int doc_from_parent);

/* ******-REDIR N EXEC****************************************************** */

char		**format_cmd(t_token *cmd_tok);
int			get_tab_len(t_token *cmd_tok);
char		**allocate_and_fill_command_array(t_token *cmd_tok, int tab_len);
int			check_for_the_cmd(char *path, char *cmd);

void		redir(t_shell *shell, t_token *token, t_token_type type);
void		input(t_shell *shell, t_token *token);
int			pipe_n_fork(t_shell *shell);

int			exec_bin(char **cmd_arg, t_env *env);

/* ******-FDs STDs CLEANUP************************************************** */

bool		close_fd(int fd);
void		close_reset_fd(t_shell *shell);
void		reset_stds(t_shell *shell);
void		cleanup_shell(t_shell *shell);

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

char		*make_var_name(char *var, int to_trim);

/* ******-******************************************************************* */

bool		already_set(t_env *env, char *name, int len, char *var_value);
void		add_in_lex_order(t_env **first, t_env *new_var);
void		set_var(t_env **env, char *name, char *value, int exp_env);

/* ******-PARSER************************************************************* */

void		final_process(t_token *tokens, t_env *envp, t_shell *shell);
char		*handle_in_quotes(char *str, t_env *envp, t_shell *shell);

#endif
