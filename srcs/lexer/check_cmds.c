/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:20:39 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/13 15:08:49 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_pipe(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok->type != PIPE && tok_str[0] == '|')
		return (true);
	return (false);
}

bool	check_cmd(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok->prev == NULL)
		return (true);
	while (tok)
	{
		if (tok->type == PIPE)
			break;
		if (tok->type == CMD || tok->type == CMD_PATH)
			return (false);
		tok = tok->prev;
	}
	return (true);
}

bool	check_cmd_path(char *tok_str, t_token *tok)
{
	int	flag;

	flag = 0;
	while (tok_str)
	{
		if (*tok_str == '/')
			flag = 1;
		tok_str++;
	}
	if (tok->prev == NULL && flag)
		return (true);
	while (tok)
	{
		if (tok->type == PIPE && flag)
			break;
		if ((tok->type == CMD || tok->type == CMD_PATH) && flag)
			return (false);
		tok = tok->prev;
	}
	return (true);
}

bool	check_arg(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok->type == false)
		return (true);
	return (false);
}
