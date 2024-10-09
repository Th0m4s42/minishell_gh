/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:38:12 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:31:28 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (*((unsigned char *)pointer1 + i)
			!= *((unsigned char *)pointer2 + i))
			return (*((unsigned char *)pointer1 + i)
				- *((unsigned char *)pointer2 + i));
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
	char s[] = {-128, 0, 127, 0};
	char spy[] = {-128, 0, 127, 0};

	printf("%i\n", ft_memcmp(s, spy, 4));
	printf("%i\n", memcmp(s, spy, 4));
	return(0);
}
*/
