/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:27:44 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/10 08:36:17 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_hex(unsigned int nb, char specifier)
{
	int		count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_print_hex(nb / 16, specifier);
		count += ft_print_hex(nb % 16, specifier);
	}
	else
	{
		if (nb <= 9)
			count += ft_printchar(nb + '0');
		else
		{
			if (specifier == 'x')
				count += ft_printchar(nb - 10 + 'a');
			if (specifier == 'X')
				count += ft_printchar(nb - 10 + 'A');
		}
	}
	return (count);
}

int	ft_printhex(unsigned int nb, char specifier)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += ft_printchar('0');
		return (count);
	}
	count += ft_print_hex(nb, specifier);
	return (count);
}
