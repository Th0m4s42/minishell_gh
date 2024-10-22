/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:37:38 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/22 16:28:03 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**ft_strtok(char *string, const char *sep)
{
	int		i;
	int		j;
	char	**tok;

	if (string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	tok = malloc(sizeof(char **));
	// A finir !!
}
