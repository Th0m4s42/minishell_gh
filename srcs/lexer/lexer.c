/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/30 19:07:43 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*new_node(char **tok, t_token *last_node, int type)
{
	t_token	*node;

	if (last_node != NULL && last_node->type == REDIRECTION)
	{
		if (last_node->value != NULL)
			free(last_node->value);
		last_node->value = ft_strdup(*tok);
		last_node->type = type;
		return (last_node);
	}
	node = malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->value = ft_strdup(*tok);
	node->type = type;
	if (last_node != NULL)
		last_node->next = node;
	node->prev = last_node;
	node->next = NULL;
	return (node);
}

void	lexing(ft_array *check_type, t_token **first_node, char **tok)
{
	t_token	*tmp;
	int		i;
	int		j;
	bool	found;

	tmp = NULL;
	i = 0;
	while (tok[i])
	{
		j = 0;
		found = false;
		while (check_type[j])
		{
			if (check_type[j](tok[i], tmp) == true)
			{
				tmp = new_node(&tok[i], tmp, j);
				if (tmp == NULL)
				{
					free_list_lex(first_node);
					ft_free_tab(tok);
					return ;
				}
				if (*first_node == NULL)
					*first_node = tmp;
				found = true;
				break ;
			}
			j++;
		}
		if (!found)
		{
			ft_putstr_fd("syntax error near unexpected token '", 2);
			ft_putstr_fd(tok[i], 2);
			ft_putendl_fd("'", 2);
			free_list_lex(first_node);
			ft_free_tab(tok);
			// free tableau puis liste chainee
			return ;
		}
		i++;
	}
}

t_token	*lexer(char *rl_value)
{
	ft_array	check_type[10];
	t_token		*first_node;
	char		**tok;

	tok = ft_strtok(rl_value, " \t\v\n\r\f");
	if (tok == NULL)
		return (NULL);
	first_node = NULL;
	init_functionarray(&check_type);
	lexing(check_type, &first_node, tok);
	return (first_node);
}
