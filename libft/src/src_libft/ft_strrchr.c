/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:08:16 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:45:36 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	unsigned char	target_char;
	char			*last_occurrence;

	target_char = (unsigned char)searchedChar;
	last_occurrence = (char *) NULL;
	while (*string != '\0')
	{
		if (*string == target_char)
			last_occurrence = (char *)string;
		string++;
	}
	if (target_char == '\0')
		return ((char *)string);
	return ((char *)last_occurrence);
}
