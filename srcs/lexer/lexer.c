/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:38 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/22 17:30:46 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	toklen(char *string, char *sep)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && !is_sep(string[i], sep))
		i++;
	return (i);
}

static int	is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static int	tok_count(char *string, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (is_sep(string[i], sep))
			count++;
		i++;
	}
	count++;
	return (count);
}

char	**ft_strtok(char *string, const char *sep)
{
	int		i;
	int		t;
	int		tok_len;
	char	**tok;

	if (string == NULL)
		return (NULL);
	tok = malloc(sizeof(char *) * (tok_count(string, sep) + 1));
	if (tok == NULL)
		return (NULL);
	i = 0;
	t = 0;
	while (t < tok_count(string, sep))
	{
		while (is_sep(string[i], sep))
			i++;
		tok_len = toklen(string, sep);
		t++;
	}
	return (tok);
}

	// A finir !!