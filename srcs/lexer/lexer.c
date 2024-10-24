/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:38 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/24 15:26:50 by thbasse          ###   ########.fr       */
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

static int toklen(char *string, char *sep)
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

static int	tok_count(char *string, char *sep)
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
	printf("tok_len: %d\n", tok_len);
	if (tok_len == 0)
		return (NULL);
	token = malloc(sizeof(char) * (tok_len + 1));
	if (token == NULL)
		return (NULL);
	ft_strlcpy(token, &string[*index], tok_len + 1);
	(*index) += tok_len;
	return (token);
}

char	**ft_strtok(char *string, char *sep)
{
	int		index;
	int		t;
	char	**tok;

	if (string == NULL)
		return (NULL);
	tok = allocate_tokens(string, sep);
	if (tok == NULL)
		return (NULL);
	index = 0;
	t = 0;
	while (t < tok_count(string, sep))
	{
		tok[t] = extract_token(string, sep, &index);
		if (tok[t] == NULL)
		{
			free(tok);
			return (NULL);
		}
		t++;
	}
	tok[t] = NULL;
	return (tok);
}
