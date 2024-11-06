/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirictions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:21:00 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/06 17:14:07 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_in(char *token, t_token *type)
{
	(void)token;
	(void)type;
	return (false);
}

bool	check_heredoc(char *token, t_token *type)
{
	(void)token;
	(void)type;
	return (false);
}

bool	check_append(char *token, t_token *type)
{
	(void)token;
	(void)type;
	return (false);
}

bool	check_trunc(char *token, t_token *type)
{
	(void)token;
	(void)type;
	return (false);
}
