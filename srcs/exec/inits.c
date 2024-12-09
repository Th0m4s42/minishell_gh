/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:00:49 by noam              #+#    #+#             */
/*   Updated: 2024/12/06 01:03:08 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*add_end_tok(t_token *toks)
{
	t_token	*tmp;
	t_token	*end_tok;

	tmp = toks;
	end_tok = (t_token *)malloc(sizeof(t_token));
	if (!end_tok)
		return (NULL);
	end_tok->value = ft_substr("end", 0, 3);
	end_tok->type = END;
	end_tok->next = NULL;
	end_tok->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = end_tok;
	end_tok->prev = tmp;
	return (toks);
}

/* ************************************************************************** */

void	init_shell(t_shell *shell, char **envp)
{
	shell->start = NULL;
	shell->env = get_env(envp);
	shell->in = dup(STDIN);
	shell->out = dup(STDOUT);
	shell->fdin = 0;
	shell->fdout = 0;
	shell->pipin = -1;
	shell->pipout = -1;
	shell->pid = 0;
	shell->charge = 0;
	shell->parent = 0;
	shell->exec = 1;
}
