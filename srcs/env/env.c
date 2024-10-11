/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:49 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/11 15:13:08 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_env_variable_name(char *envp, char *name)
{
	int	i;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	ft_strlcpy(name, envp, i);
	return (name);
}

char	*get_env_variable_value(char *envp, char *value)
{
	int	i;
	
	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	if (envp[i] == '=')
		i++;
	ft_strlcpy(value, &envp[i], ft_strlen(&envp[i]) + 1);
	return (value);
}

t_env	*get_env(char **envp)
{
	t_env	*env;
	char	name[256];
	char	value[256];

	env = NULL;
	while(envp)
	{
		get_env_variable_name(*envp, name);
		get_env_variable_value(*envp, value);
		if (env == NULL)
			env = new_env_node(name, value);
		else
		{
			while(env)
				env = env->next;
			env->next = new_env_node(name, value);
		}
		envp++;
	}
	return (env);
}
