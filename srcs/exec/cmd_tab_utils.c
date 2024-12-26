/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tab_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:20:36 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 00:25:36 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

int	get_tab_len(t_token *cmd_tok)
{
	t_token	*tok;
	int		tab_len;

	tok = cmd_tok;
	tab_len = 0;
	if (!tok || !tok->value)
		return (0);
	while (tok && tok->type != END && (tok->type != PIPE || !tab_len))
	{
		if (tok->type <= 4)
		{
			tok = tok->next;
			continue ;
		}
		tab_len++;
		tok = tok->next;
	}
	return (tab_len);
}

/* ************************************************************************** */

char	**allocate_and_fill_command_array(t_token *cmd_tok, int tab_len)
{
	char	**format_cmd;
	t_token	*tok;
	int		i;

	format_cmd = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!format_cmd)
		return (NULL);
	tok = cmd_tok;
	i = 0;
	while (tok && tok->type != END && (tok->type != PIPE || i == 0))
	{
		if (tok->type <= 4)
		{
			tok = tok->next;
			continue ;
		}
		if (tok->value)
			format_cmd[i] = ft_strdup(tok->value);
		else
			format_cmd[i] = ft_strdup("");
		i++;
		tok = tok->next;
	}
	format_cmd[i] = NULL;
	return (format_cmd);
}

char	**format_cmd(t_token *cmd_tok)
{
	char	**format_cmd;
	int		tab_len;

	tab_len = get_tab_len(cmd_tok);
	if (tab_len == 0)
		return (NULL);
	format_cmd = allocate_and_fill_command_array(cmd_tok, tab_len);
	return (format_cmd);
}
