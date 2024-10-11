/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:49 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/11 18:26:53 by thbasse          ###   ########.fr       */
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

t_env	*get_env(char **envp)
{
	t_env	*env_list;
	t_env	*new_node;
	char	*name;
	char	*value;

	env_list = NULL;
	while (*envp)
	{
		name = NULL;
		value = NULL;
		if (get_env_variable_name(*envp, &name) == false)
			return (free_env_list(&env_list), NULL);
		if (get_env_variable_value(*envp, &value) == false)
		{
			free(name);
			return (free_env_list(&env_list), NULL);
		}
		new_node = new_env_node(name, value);
		if (new_node == NULL)
			return (free_env_list(&env_list), NULL);
		add_back(&env_list, new_node);
		envp++;
	}
	return (env_list);
}
