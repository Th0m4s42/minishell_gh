/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:02 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/25 16:11:28 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

////////////////////////////////////////////////////////////////////////////////
//								ENUM										  //
////////////////////////////////////////////////////////////////////////////////

typedef enum s_token_type
{
	CMD,
	CMD_PATH,
	ARG,
	PIPE,
	IN,
	HERE_DOC,
	APPEND,
	TRUNC
}	t_token_type;

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

typedef bool (*ptr_to_ft_array)(char *, t_token *);

/* tab_token_utils.c */

int		is_sep(char c, char *sep);
int		toklen(char *string, char *sep);
int		tok_count(char *string, char *sep);
char	**allocate_tokens(char *string, char *sep);
void	ft_free_tab(char **tab);

/* token.c */

char	*extract_token(char *string, char *sep, int *index);
char	**ft_strtok(char *string, char *sep);

/* lexer.c */

/* list_lex_manip.c */
t_token	*new_env_node(char *value, t_token_type *type);
void	free_env_list(t_token **first_node);
void	add_back(t_token **first, t_token *new);

#endif