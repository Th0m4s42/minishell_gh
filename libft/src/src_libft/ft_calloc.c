/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:38:41 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:26:36 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	memory_size;
	void	*ptr;

	memory_size = elementCount * elementSize;
	if (elementSize != 0
		&& memory_size / elementSize != elementCount)
		return (NULL);
	ptr = malloc(memory_size);
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL)
		ft_bzero(ptr, memory_size);
	return (ptr);
}
