/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:22:32 by noam              #+#    #+#             */
/*   Updated: 2024/12/25 15:35:07 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

t_token	*next_sep(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (token && token->type > PIPE && token->type != END)
		token = token->next;
	if (token == tmp)
		token = token->next;
	return (token);
}

t_token	*prev_sep(t_token *token)
{
	if (!token->prev)
		return (NULL);
	while (token && token->type > PIPE)
		token = token->prev;
	return (token);
}

int	is_type(t_token *token, t_token_type type)
{
	if (token && token->type == type)
		return (1);
	else
		return (0);
}

int	get_tab_len(t_token *cmd_tok)
{
	t_token	*tok;
	int		tab_len;

	tok = cmd_tok;
	tab_len = 0;
	if (!tok || !tok->value)
		return (0);
	while (tok && (tok->type == ARG || !tab_len))
	{
		tab_len++;
		tok = tok->next;
	}
	return (tab_len);
}

/* ************************************************************************** */

char	**format_cmd(t_token *cmd_tok)
{
	char	**format_cmd;
	t_token	*tok;
	int		tab_len;
	int		i;

	tab_len = get_tab_len(cmd_tok);
	tok = cmd_tok;
	i = 0;
	if (tab_len == 0)
		return (NULL);
	format_cmd = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!format_cmd)
		return (NULL);
	while (tok && (tok->type == ARG || i == 0))
	{
		if (tok->value)
			format_cmd[i] = ft_strdup(tok->value);
		else
			format_cmd[i] = ft_strdup("\0");
		i++;
		tok = tok->next;
	}
	format_cmd[i] = NULL;
	return (format_cmd);
}

// char	*ft_strjoin_free(char *s1, char *s2, int free_ss)
// {
// 	char	*ptr;

// 	ptr = ft_strjoin(s1, s2);
// 	if (free_ss == 1 && s1)
// 		free(s1);
// 	else if (free_ss == 2 && s2)
// 		free(s2);
// 	else if (free_ss == 3 && (s1 || s2))
// 	{
// 		if (s1)
// 			free(s1);
// 		if (s2)
// 			free(s2);
// 	}
// 	return (ptr);
// }

// bool	has_backslash(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '/')
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }
