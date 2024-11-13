/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maja <maja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/13 17:55:35 by maja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*new_node(char **tok, t_token *last_node, int type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->value = *tok;
	node->type = type;
	last_node->next = node;
	node->prev = last_node;
	return (node);
}

void	lexing(ft_array *check_type, t_token **first_node, char **tok)
{
	t_token	*tmp;
	int		i;
	int		j;

	tmp = NULL;
	*first_node = tmp;
	i = 0;
	while (tok[i])
	{
		j = 0;
		while (check_type[j])
		{
			if (check_type[j](tok[i], tmp) == true)
			{
				tmp = new_node(tok, tmp, j);
				if (tmp == NULL)
					printf("Ne pas oublier de faire des trucs ici :)");
				break ;
			}
			j++;
		}
		i++;
	}
}

t_token	*lexer(char *rl_value)
{
	ft_array	check_type[9];
	t_token		*first_node;
	char		**tok;

	tok = ft_strtok(rl_value, " \t\v\n\r\f");
	if (tok == NULL)
		return (NULL);
	first_node = NULL;
	init_functionarray(&check_type);
	lexing(check_type, &first_node, tok);
	return (NULL);
}
