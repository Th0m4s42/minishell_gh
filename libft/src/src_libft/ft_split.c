/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:10:48 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:37:12 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	str_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

static size_t	str_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*str_copy(char const *s, char c)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = str_len(s, c);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (*s != c && *s != '\0')
		copy[i++] = *s++;
	copy[i] = '\0';
	return (copy);
}

static char	**split_eff(char const *s, char c, char **arr)
{
	size_t	curr_str;

	curr_str = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			arr[curr_str] = str_copy(s, c);
			if (arr[curr_str] == NULL)
			{
				while (curr_str > 0)
					free(arr[--curr_str]);
				free(arr);
				return (NULL);
			}
			curr_str++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	arr[curr_str] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (str_count(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	return (split_eff(s, c, arr));
}
