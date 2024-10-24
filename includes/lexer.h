/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:02 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/24 16:36:22 by thbasse          ###   ########.fr       */
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
	char			*string;
	t_token_type	token;
}	t_token;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

/* tab_token_utils.c */

int		is_sep(char c, char *sep);
int		toklen(char *string, char *sep);
int		tok_count(char *string, char *sep);
char	**allocate_tokens(char *string, char *sep);

/* token.c */
char	*extract_token(char *string, char *sep, int *index);
char	**ft_strtok(char *string, char *sep);

#endif