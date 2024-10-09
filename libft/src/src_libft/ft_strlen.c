/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:21:36 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/21 12:56:46 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen( const char *theString )
{
	size_t	i;

	i = 0;
	if (theString == NULL)
		return (0);
	while (theString[i])
		i++;
	return (i);
}
