/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:21:00 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/19 15:06:55 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_redirection(char *token, t_token *tok)
{
	if (tok != NULL && tok->type == REDIRECTION)
		return (false);
	else if (token[0] == '<' || token[0] == '>')
		return (true);
	return (false);
}

bool	check_infile(char *token, t_token *tok)
{
	(void)token;
	if (tok != NULL && tok->value[0] == '<' && tok->value[1] == '\0'
		&& tok->type == REDIRECTION && token[0] != '|')
		return (true);
	return (false);
}

bool	check_heredoc(char *token, t_token *tok)
{
	(void)token;
	if (tok != NULL && tok->value[0] == '<' && tok->value[1] == '<'
		&& tok->value[2] == '\0' && tok->type == REDIRECTION && token[0] != '|')
		return (true);
	return (false);
}

bool	check_outfile(char *token, t_token *tok)
{
	(void)token;
	if (tok != NULL && tok->value[0] == '>' && tok->value[1] == '\0'
		&& tok->type == REDIRECTION && token[0] != '|')
		return (true);
	return (false);
}

bool	check_append(char *token, t_token *tok)
{
	(void)token;
	if (tok != NULL && tok->value[0] == '>' && tok->value[1] == '>'
		&& tok->value[2] == '\0' && tok->type == REDIRECTION && token[0] != '|')
		return (true);
	return (false);
}
