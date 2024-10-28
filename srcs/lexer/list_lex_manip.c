/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lex_manip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:29:43 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/28 17:17:20 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*new_tok_node(char *value, t_token_type *type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->type = type;
	node->next = NULL;
	return (node);
}

void	free_tok_list(t_token **first_node)
{
	t_token	*tmp;

	if (first_node == NULL)
		return ;
	while (*first_node != NULL)
	{
		tmp = (*first_node)->next;
		free((*first_node)->value);
		free(*first_node);
		*first_node = tmp;
	}
	*first_node = NULL;
}

void	add_back(t_token **first, t_token *new)
{
	t_token	*last;

	last = *first;
	if (*first == NULL)
	{
		*first = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}
