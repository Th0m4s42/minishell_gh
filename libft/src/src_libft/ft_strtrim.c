/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:37:54 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:45:49 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*ft_mavide(void)
{
	char	*ptr;

	ptr = malloc(1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*new_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	begin = 0;
	while (begin < len && ft_strchr(set, s1[begin]))
		begin++;
	if (begin == len)
		return (ft_mavide());
	end = len - 1;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	new_s = malloc(end - begin + 2);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (begin <= end)
		new_s[i++] = s1[begin++];
	new_s[i] = '\0';
	return (new_s);
}
