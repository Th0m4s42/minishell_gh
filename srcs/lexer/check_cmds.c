/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:20:39 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/16 15:27:36 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	check_pipe(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok != NULL && tok->type != PIPE && tok_str[0] == '|')
		return (true);
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
	while (tok)
	{
		if (tok->type == PIPE && flag == 1)
			return (true);
		if ((tok->type != CMD && tok->type != CMD_PATH) && flag == 1)
			return (true);
		tok = tok->prev;
	}
	return (false);
}

bool	check_cmd(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok == NULL)
		return (true);
	while(tok && tok->type >= 1 && tok->type <=4)
		tok = tok->prev;
	if (tok->type == PIPE)
		return (true);
	if (tok->type != CMD && tok->type != CMD_PATH)
		return (true);
	return (false);
}

bool	check_arg(char *tok_str, t_token *tok)
{
	(void)tok_str;
	if (tok != NULL &&
		(tok->type == CMD || tok->type == CMD_PATH || tok->type == ARG))
		return (true);
	return (false);
}
