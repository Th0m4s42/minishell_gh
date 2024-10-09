/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:38:03 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:39:43 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	unsigned char	target_char;

	target_char = (unsigned char)searchedChar;
	while (*string != 0)
	{
		if (*string == target_char)
			return ((char *)string);
		string++;
	}
	if (searchedChar == '\0')
		return ((char *)string);
	return (NULL);
}
