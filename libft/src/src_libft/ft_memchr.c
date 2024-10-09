/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:43:49 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:30:57 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	const unsigned char	*mem_adress;
	unsigned char		target_char;

	mem_adress = (const unsigned char *)memoryBlock;
	target_char = (unsigned char)searchedChar;
	while (size > 0)
	{
		if (*mem_adress == target_char)
			return ((void *)mem_adress);
		mem_adress++;
		size--;
	}
	return (NULL);
}
