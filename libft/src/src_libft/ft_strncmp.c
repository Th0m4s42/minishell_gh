/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:18:25 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:44:36 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	while (length > 0)
	{
		if (*first != *second)
			return ((unsigned char)*first - (unsigned char)*second);
		if (*first == '\0')
			break ;
		first++;
		second++;
		length--;
	}
	return (0);
}
