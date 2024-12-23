/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:31:55 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/23 16:29:19 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	is_redirection(char c)
{
	return (c == '<' || c == '>');
}

int	tok_count(char *string, char *sep)
{
	int	index;
	int	count;
	int	len;

	index = 0;
	count = 0;
	while (string[index])
	{
		while (is_sep(string[index], sep))
			index++;
		if (string[index])
		{
			len = toklen(&string[index], sep);
			if (len == -1)
				return (-1);
			count++;
			index += len;
			if (is_redirection(string[index - 1])
				&& string[index] == string[index - 1])
				index++;
		}
	}
	return (count);
}

void	ft_free_tab(char **tab)
{
	int	index;

	if (tab == NULL)
		return ;
	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		tab[index] = NULL;
		index++;
	}
	free(tab);
}
