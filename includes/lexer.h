/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:02 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/13 17:24:54 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

////////////////////////////////////////////////////////////////////////////////
//								ENUM										  //
////////////////////////////////////////////////////////////////////////////////

typedef enum s_token_type
{
	REDIRECTION,
	INFILE,
	HEREDOC,
	APPEND,
	OUTFILE,
	PIPE,
	CMD_PATH,
	CMD,
	ARG
}	t_token_type;

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_token
{
	struct s_token	*prev;
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

typedef bool (*ft_array)(char *, t_token *);

/* tab_token_utils.c */

int		is_sep(char c, char *sep);
int		is_redirection(char c);
int		toklen(char *string, char *sep);
int		tok_count(char *string, char *sep);
void	ft_free_tab(char **tab);

/* token.c */

char	*extract_token(char *string, char *sep, int *index);
char	**allocate_tokens(char *string, char *sep);
char	**ft_strtok(char *string, char *sep);

/* lexer.c */

void	init_functionarray(ft_array (*funct_array)[9]);
bool	check_redirection(char *tok_str, t_token *tok);
bool	check_infile(char *token, t_token *tok);
bool	check_heredoc(char *token, t_token *tok);
bool	check_outfile(char *token, t_token *tok);
bool	check_append(char *token, t_token *tok);
bool	check_pipe(char *tok_str, t_token *tok);
bool	check_cmd_path(char *tok_str, t_token *tok);
bool	check_cmd(char *tok_str, t_token *tok);
bool	check_arg(char *tok_str, t_token *tok);
t_token	*new_node(char **tok, t_token *new_node, int type);
void	lexing(ft_array *check_type, t_token **first_node, char **tok);
t_token	*lexer(char *rl_value);

/* list_lex_manip.c */

t_token	*new_tok_node(char *value, t_token_type *type);
void	free_tok_list(t_token **first_node);
void	add_back_tok(t_token **first, t_token *new);

#endif