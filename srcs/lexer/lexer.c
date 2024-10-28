/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/28 17:35:20 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*new_node(char ** tok, t_token *new_node)
{
	return (new_node);
}

void	lexing(ft_array check_type, t_token **first_node, char **tok)
{
	t_token	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	*first_node = tmp;
	i = 0;
	while (tok[i])
	{
		while ((check_type + j)(tok[i], tmp))
		{
			if (check_type + j == true)
			{
				// tmp = fonction qui cree le new_node qui return le pointeur
				// vers le dernier noeud cree
				break ;
			}
			j++;
		}
		i++;
	}
}

t_token	*lexer(char *rl_value)
{
	ft_array	check_type[8];
	t_token		*first_node;
	char		**tok;

	tok = ft_strtok(rl_value, " \t\v\n\r\f");
	if (tok == NULL)
		return (NULL);
	first_node = NULL;
	init_functionarray(&check_type);
	lexing(&check_type, first_node, tok);
}
