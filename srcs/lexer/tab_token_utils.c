/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_token_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:31:55 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/24 16:45:53 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <minishell.h>

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

int	toklen(char *string, char *sep)
{
	int len;
	char quote;

	len = 0;
	quote = '\0';
	while (string[len])
	{
		if (string[len] == '\'' || string[len] == '\"')
		{
			if (quote == '\0')
				quote = string[len];
			else if (quote == string[len])
				quote = '\0';
		}
		else if (quote == '\0' && is_sep(string[len], sep))
			break;
		len++;
	}
	return (len);
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
		}
	}
	return (count);
}

char	**allocate_tokens(char *string, char *sep)
{
	int count;
	char **tok;

	count = tok_count(string, sep);
	tok = malloc(sizeof(char *) * (count + 1));
	if (tok == NULL)
		return (NULL);
	return (tok);
}

void	ft_free_tab(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		index++;
	}
	free(tab);
}
