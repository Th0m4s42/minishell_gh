/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:20:39 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/20 15:03:45 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_pipe(char *tok_str, t_token *tok)
{
	if (tok_str[0] == '|' && tok_str[1] == '\0')
	{
		if (tok != NULL && tok->type == PIPE)
			return (false);
		return (true);
	}
	return (false);
}

bool	check_cmd_path(char *tok_str, t_token *tok)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (tok_str[i])
	{
		if (tok_str[i] == '/')
			flag = 1;
		i++;
	}
	while(tok && tok->type >= 1 && tok->type <= 4)
		tok = tok->prev;
	if (tok == NULL && flag == 1)
		return (true);
	if (tok->type == PIPE && flag == 1)
		return (true);
	return (false);
}

bool	check_cmd(char *tok_str, t_token *tok)
{
	(void)tok_str;
	while(tok && tok->type >= 1 && tok->type <=4)
		tok = tok->prev;
	if (tok == NULL)
		return (true);
	if (tok->type == PIPE && tok_str[0] != '|' && tok_str[1] != '\0')
		return (true);
	return (false);
}

bool	check_arg(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok != NULL &&
		(tok->type == CMD || tok->type == CMD_PATH || tok->type == ARG) &&
		(tok->type != PIPE && tok->type != REDIRECTION))
		return (true);
	return (false);
}
