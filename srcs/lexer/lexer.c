/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/25 18:10:49 by thbasse          ###   ########.fr       */
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

t_token	*process_token(t_array *check_type, t_token **first_node, char *token,
	t_token *last_node)
{
	t_token	*new_node_result;
	int		j;
	bool	found;

	j = 0;
	found = false;
	while (check_type[j])
	{
		if (check_type[j](token, last_node) == true)
		{
			new_node_result = new_node(&token, last_node, j);
			if (new_node_result == NULL)
				return (NULL);
			if (*first_node == NULL)
				*first_node = new_node_result;
			return (new_node_result);
		}
		j++;
	}
	if (!found)
	{
		handle_syntax_error(token, first_node);
		return (NULL);
	}
	return (last_node);
}

int	lexing(t_array *check_type, t_token **first_node, char **tok, int i)
{
	t_token	*tmp;

	tmp = NULL;
	while (tok[i])
	{
		if (has_syntax_error(tok, i))
		{
			handle_syntax_error(tok[i], first_node);
			return (1);
		}
		tmp = process_token(check_type, first_node, tok[i], tmp);
		if (tmp == NULL)
		{
			free_tok_list(first_node);
			return (1);
		}
		i++;
	}
	if (is_invalid_final_token(tmp))
	{
		handle_syntax_error(tok[i - 1], first_node);
		return (1);
	}
	return (0);
}

t_token	*lexer(char *rl_value, int *ret)
{
	t_array		check_type[10];
	t_token		*first_node;
	char		**tok;

	tok = ft_strtok(rl_value, " \t\v\n\r\f\0");
	if (tok == NULL || *tok == NULL)
	{
		ft_free_tab(tok);
		tok = NULL;
		return (NULL);
	}
	first_node = NULL;
	init_functionarray(&check_type);
	if (lexing(check_type, &first_node, tok, 0) == 1)
		*ret = 2;
	ft_free_tab(tok);
	tok = NULL;
	return (first_node);
}
