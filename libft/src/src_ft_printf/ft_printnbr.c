/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:43:07 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/09 10:11:12 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printnbr(int n)
{
	long long int	count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_printnbr(n / 10);
		count += ft_printchar(n % 10 + '0');
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}
