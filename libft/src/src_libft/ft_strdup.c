/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:02:55 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:40:02 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *source)
{
	char	*ptr;
	size_t	length;

	length = ft_strlen(source) + 1;
	ptr = malloc(length);
	if (source == NULL)
		return (NULL);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, source, length);
	return (ptr);
}
