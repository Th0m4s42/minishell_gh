/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exc_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:22:32 by noam              #+#    #+#             */
/*   Updated: 2024/11/27 17:52:57 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

t_token	*next_sep(t_token *token)
{
	while (token && token->type > PIPE && token->type != END)
		token = token->next;
	return (token);
}

t_token	*prev_sep(t_token *token)
{
	while (token && token->type > PIPE && token->type != END)
		token = token->prev;
	return (token);
}

int	is_type(t_token *token, t_token_type type)
{
	if (token && token->type == type)
	{
		// fprintf(stderr, "type: %d\n", token->type);
		return (1);
	}
	else
		return (0);
}

