/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:41:36 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:35:16 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *dest, int value, size_t count)
{
	size_t	i;
	char	*char_dest;

	i = 0;
	char_dest = (char *)dest;
	while (i < count)
	{
		char_dest[i] = (char)value;
		i++;
	}
	return (dest);
}
