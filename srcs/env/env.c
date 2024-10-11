/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:49 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/11 16:27:40 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	get_env_variable_name(char *envp, char **name)
{
	int	i;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	*name = malloc(sizeof(char) * (i + 1));
	if (*name == NULL)
		return (false);
	ft_strlcpy(*name, envp, i + 1);
	return (true);
}

bool	get_env_variable_value(char *envp, char **value)
{
	int	i;
	
	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	if (envp[i] == '\0')
		return (true);
	i++;
	*value = malloc(sizeof(char) * (ft_strlen(envp) - i + 1));
	if (*value == NULL)
		return (false);
	ft_strlcpy(*value, envp + i, ft_strlen(envp + i) + 1);
	return (true);
}

static void add_back(t_env **first, t_env *new)
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

t_env	*get_env(char **envp)
{
	t_env	*env_list;
	t_env	*new_node;
	char	*name;
	char	*value;

	name = NULL;
	value = NULL;
	env_list = NULL;
	while(*envp)
	{
		get_env_variable_name(*envp, &name);
		get_env_variable_value(*envp, &value);
		new_node = new_env_node(name, value);
		add_back(&env_list, new_node);
		envp++;
	}
	return (env_list);
}
