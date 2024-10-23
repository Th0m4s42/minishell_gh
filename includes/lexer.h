/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:02 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/23 14:15:19 by thbasse          ###   ########.fr       */
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

#endif