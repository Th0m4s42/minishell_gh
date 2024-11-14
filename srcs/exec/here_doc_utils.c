/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:25 by noam              #+#    #+#             */
/*   Updated: 2024/11/14 16:10:20 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include "../../libft/includes/libft.h"
#include "../../libft/includes/get_next_line.h"

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
