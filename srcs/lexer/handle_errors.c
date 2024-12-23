/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:42:19 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/23 14:38:58 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_syntax_error(char **tok, int i)
{
	if ((ft_strchr(tok[i], '<') != NULL || ft_strchr(tok[i], '>') != NULL)
		&& (tok[i + 1] && (ft_strchr(tok[i + 1], '<') != NULL
				|| ft_strchr(tok[i + 1], '>') != NULL)))
		return (true);
	return (false);
}

void	handle_syntax_error(char *token, t_token **first_node)
{
	ft_putstr_fd("syntax error near unexpected token '", 2);
	ft_putstr_fd(token, 2);
	ft_putendl_fd("'", 2);
	free_tok_list(first_node);
	g_lobal_exit_code = 2;
}

bool	is_invalid_final_token(t_token *last_node)
{
	if (last_node && (last_node->type == PIPE
			|| last_node->type == REDIRECTION))
		return (true);
	return (false);
}
