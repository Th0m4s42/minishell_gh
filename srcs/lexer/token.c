/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:38 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/19 15:10:10 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*extract_token(char *string, char *sep, int *index)
{
	int		tok_len;
	char	*token;

	while (is_sep(string[*index], sep))
		(*index)++;
	if (string[*index] == '|' || is_redirection(string[*index]))
	{
		if (is_redirection(string[*index])
			&& string[*index] == string[*index + 1])
			tok_len = 2;
		else
			tok_len = 1;
	}
	else
		tok_len = toklen(&string[*index], sep);
	if (tok_len == 0)
		return (NULL);
	token = malloc(sizeof(char) * (tok_len + 1));
	if (token == NULL)
		return (NULL);
	ft_strlcpy(token, &string[*index], tok_len + 1);
	(*index) += tok_len;
	return (token);
}

char	**allocate_tokens(char *string, char *sep)
{
	int		count;
	char	**tok;

	if (string == NULL && *string == '\0')
	{
		free(string);
		return (NULL);
	}
	count = tok_count(string, sep);
	tok = malloc(sizeof(char *) * (count + 1));
	if (tok == NULL && *(*tok) == '\0')
	{
		free(tok);
		return (NULL);
	}
	return (tok);
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
			ft_free_tab(tok);
			return (NULL);
		}
		t++;
	}
	tok[t] = NULL;
	return (tok);
}
