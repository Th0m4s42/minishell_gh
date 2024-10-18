/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_env_manip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:43:06 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/18 10:50:04 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env	*new_env_node(char *content, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (node == NULL)
		return (NULL);
	node->name = content;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	free_env_list(t_env **first_node)
{
	t_env	*tmp;

	if (first_node == NULL)
		return ;
	while (*first_node != NULL)
	{
		tmp = (*first_node)->next;
		free((*first_node)->name);
		free((*first_node)->value);
		free(*first_node);
		*first_node = tmp;
	}
	*first_node = NULL;
}

void	add_back(t_env **first, t_env *new)
{
	t_env	*last;

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

char	*get_value_by_name(t_env *env, char *name)
{
	size_t	len;

	if (env == NULL)
		return (NULL);
	len = ft_strlen(name);
	while (env)
	{
		if (ft_strncmp(name, env->name, len + 1) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return (NULL);
}
