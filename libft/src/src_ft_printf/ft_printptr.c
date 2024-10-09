/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:53:49 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/10 08:29:16 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count += ft_print_ptr(ptr / 16);
		count += ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			count += ft_printchar(ptr + '0');
		else
			count += ft_printchar(ptr - 10 + 'a');
	}
	return (count);
}

int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (count);
	}
	write(1, "0x", 2);
	count = 2;
	count += ft_print_ptr(ptr);
	return (count);
}
