/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:13:17 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:32:20 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (dest == src || size == 0)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < size)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		dest = ((char *)dest + size);
		src = ((char *)src + size);
		while (size--)
			*((char *)--dest) = *((char *)--src);
	}
	return (dest);
}
