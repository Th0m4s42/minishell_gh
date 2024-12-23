/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toklen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:22:37 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/23 16:32:38 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	toklen(char *string, char *sep)
{
	int		len;
	char	quote;

	len = 0;
	quote = '\0';
	while (string[len])
	{
		if (is_quote(string[len]))
			handle_quote(&quote, string[len]);
		else if (quote == '\0')
		{
			if (is_special_separator(string[len]))
				return (get_token_length(len));
			if (is_sep(string[len], sep))
				break ;
		}
		len++;
	}
	return (len);
}

int	is_quote(char c)
{
	return (c == '\'' || c == '\"');
}

void	handle_quote(char *current_quote, char c)
{
	if (*current_quote == '\0')
		*current_quote = c;
	else if (*current_quote == c)
		*current_quote = '\0';
}

int	is_special_separator(char c)
{
	return (c == '|' || is_redirection(c));
}

int	get_token_length(int len)
{
	if (len == 0)
		return (1);
	return (len);
}
