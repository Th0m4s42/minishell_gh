/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:34:13 by noam              #+#    #+#             */
/*   Updated: 2024/12/25 15:34:40 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_strjoin_free(char *s1, char *s2, int free_ss)
{
	char	*ptr;

	ptr = ft_strjoin(s1, s2);
	if (free_ss == 1 && s1)
		free(s1);
	else if (free_ss == 2 && s2)
		free(s2);
	else if (free_ss == 3 && (s1 || s2))
	{
		if (s1)
			free(s1);
		if (s2)
			free(s2);
	}
	return (ptr);
}

/* ************************************************************************** */

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
