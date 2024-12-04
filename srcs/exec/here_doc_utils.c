/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:25 by noam              #+#    #+#             */
/*   Updated: 2024/12/04 14:50:39 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	until_space(char *str, int i)
{
	if (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n'
		&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
		i++;
	while (str[i] && (str[i] != '\t' && str[i] != ' ' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r'))
		i++;
	return (i);
}

bool	has_dolla_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	until_dolla_sign(char *str, int i)
{
	while (str[i] && str[i] != '$')
		i++;
	return (i);
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
