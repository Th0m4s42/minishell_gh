/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:21:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/18 12:39:20 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*process_token(ft_array *check_type, t_token **first_node, char *token,
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

void	lexing(ft_array *check_type, t_token **first_node, char **tok)
{
	t_token	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (tok[i])
	{
		if (has_syntax_error(tok, i))
		{
			handle_syntax_error(tok[i], first_node);
			return ;
		}
		tmp = process_token(check_type, first_node, tok[i], tmp);
		if (tmp == NULL)
		{
			free_tok_list(first_node);
			ft_free_tab(tok);
			return ;
		}
		i++;
	}
	if (is_invalid_final_token(tmp, tok[i - 1]))
	{
		handle_syntax_error(tok[i - 1], first_node);
		return ;
	}
}

t_token	*lexer(char *rl_value)
{
	ft_array	check_type[10];
	t_token		*first_node;
	char		**tok;

	tok = ft_strtok(rl_value, " \t\v\n\r\f\0");
	if (tok == NULL || *tok == NULL)
	{
		ft_free_tab(tok);
		return (NULL);
	}
	first_node = NULL;
	init_functionarray(&check_type);
	lexing(check_type, &first_node, tok);
	ft_free_tab(tok);
	return (first_node);
}
