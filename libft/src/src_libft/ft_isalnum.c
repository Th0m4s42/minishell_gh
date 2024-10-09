/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:08:40 by thbasse           #+#    #+#             */
/*   Updated: 2023/11/15 15:40:06 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum( int character )
{
	if ((character > 64 && character < 91)
		|| (character > 96 && character < 123)
		|| (character > 47 && character < 58))
		return (1);
	else
		return (0);
}
