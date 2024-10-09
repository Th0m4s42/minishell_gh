/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:14:58 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/09 11:28:05 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printunbr(unsigned int unb)
{
	unsigned int	count;

	count = 0;
	if (unb > 9)
	{
		count += ft_printunbr(unb / 10);
		count += ft_printchar(unb % 10 + '0');
	}
	else
		count += ft_printchar(unb + '0');
	return (count);
}
