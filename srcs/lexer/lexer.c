/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:38 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/24 10:20:10 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

static int	toklen(char *string, char *sep)
{
	int	i;

	i = 0;
	while (string[i] != '\0' && !is_sep(string[i], sep))
		i++;
	return (i);
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

static char **allocate_tokens(char *string, char *sep)
{
	int count;
	char **tok;

	count = tok_count(string, sep);
	tok = malloc(sizeof(char *) * (count + 1));
	if (tok == NULL)
		return (NULL);
	return (tok);
}

char	*extract_token(char *string, char *sep, int *index)
{
	int tok_len;
	char *token;

	while (is_sep(string[*index], sep))
		(*index)++;
	tok_len = toklen(&string[*index], sep);
	token = malloc(sizeof(char) * (tok_len + 1));
		return (NULL);
	ft_strlcpy(token, &string[*index], tok_len + 1);
	while (string[*index] && !is_sep(string[*index], sep))
		(*index)++;
	
	return (token);
}

char	**ft_strtok(char *string, char *sep)
{
	int		i;
	int		t;
	int		tok_len;
	char	**tok;

	if (string == NULL)
		return (NULL);
	tok = allocate_tokens(string, sep);
	i = 0;
	t = 0;
	while (t < tok_count(string, sep))
	{
		tok[t] = extract_token(string, sep, &i);
		if (tok[t] == NULL)
			return (NULL);
		t++;
	}
	tok[t] = NULL;
	return (tok);
}
