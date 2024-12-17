/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:22:32 by noam              #+#    #+#             */
/*   Updated: 2024/12/17 19:35:12 by noam             ###   ########.fr       */
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
	if(!token->prev)
		return (NULL);
	while (token && token->type > PIPE)
		token = token->prev;
	return (token);
}

int	is_type(t_token *token, t_token_type type)
{
	if (token && token->type == type)
	{
		// fprintf(stderr, "type: %d\n", token->type);
		return (1);
	}
	else
		return (0);
}

char	*ft_strjoin_free(char *s1, char *s2, int free_ss)
{
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	if (free_ss == 1 && s1)
		free(s1);
	else if (free_ss == 2 && s2)
		free(s2);
	else if (free_ss == 3 && s1 && s2)
	{
		free(s1);
		free(s2);
	}
	return (ptr);
}

bool	has_backslash(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (true);
		i++;
	}
	return (false);
}




