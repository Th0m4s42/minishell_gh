/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:15:07 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:44:52 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *bigStr, const char *littleStr, size_t len)
{
	size_t	ls_len;
	size_t	i;
	size_t	j;

	i = 0;
	ls_len = ft_strlen(littleStr);
	if (ls_len == 0)
		return ((char *)bigStr);
	while (i < len && bigStr[i] != '\0')
	{
		j = 0;
		while (bigStr[i + j] == littleStr[j] && j < ls_len && (i + j) < len)
			j++;
		if (j == ls_len)
			return ((char *)(bigStr + i));
		i++;
	}
	return (0);
}
