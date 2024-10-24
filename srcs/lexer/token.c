/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:38 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/24 17:15:17 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*extract_token(char *string, char *sep, int *index)
{
	int		tok_len;
	char	*token;

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
			ft_free_tab(tok);
			return (NULL);
		}
		t++;
	}
	tok[t] = NULL;
	return (tok);
}
