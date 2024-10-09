/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:32 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/11 07:55:12 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printstr(const char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		count = 6;
		return (count);
	}
	while (str[i])
	{
		count += ft_printchar(str[i]);
		i++;
	}
	return (count);
}
