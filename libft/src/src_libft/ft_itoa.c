/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:20:26 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:27:11 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count_char(int n)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (n < 0)
	{
		nb = -1 * nb;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

static char	*rev_tab(char *s, int size)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < size / 2 + 1)
	{
		tmp = s[i];
		s[i] = s[size - i];
		s[size - i] = tmp;
		i++;
	}
	return (s);
}

char	*itoa_eff(char *buffer, long numb)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (numb == 0)
		buffer[i++] = '0';
	if (numb < 0)
	{
		numb *= -1;
		sign = -1;
	}
	while (numb > 0)
	{
		buffer[i++] = (numb % 10) + '0';
		numb /= 10;
	}
	if (sign != 1)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (rev_tab(buffer, i - 1));
}

char	*ft_itoa(int n)
{
	char	*buffer;
	long	nb;

	nb = n;
	buffer = malloc(sizeof(char) * (count_char(nb) + 1));
	if (buffer == NULL)
		return (0);
	itoa_eff(buffer, nb);
	return (buffer);
}
