/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/25 16:16:46 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
	prendre les tokens
	regarder leur place dans la chaine
	attribuer une valeur
*/

t_token	*lexing(char *rl_value)
{

	ptr_to_ft_array	verif_type[8];
	char	**tok;
	int		index;

	tok = ft_strtok(rl_value, " \t\v\n\r\f");
	if (tok == NULL)
		return (NULL);
	index = 0;
	while (tok[index])
	{
		
		index++;
	}
}