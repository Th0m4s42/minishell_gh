/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:28:23 by noam              #+#    #+#             */
/*   Updated: 2024/12/15 19:37:36 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	switch_value(t_env *env_var, char *new_value)
{
	if (env_var->value && env_var->value != NULL)
		free (env_var->value);
	env_var->value = new_value;
	return (true);
}

/* ************************************************************************** */

bool	already_set(t_env *env, char *name, int len, char *value)
{
	t_env	*tmp;

	tmp = env;
	if (!tmp || !name || len == 0)
		return (false);
	while (tmp)
	{
		if (ft_strncmp(name, tmp->name, len + 1) == 0)
		{
			if (!value)
			{
				free(name);
				return(true);	
			}
			switch_value(tmp, value);
			free(name);
			return(true);	
		}
		tmp = tmp->next;
	}
	return (false);
}

/* ************************************************************************** */

void	set_var(t_env **env, char *name, int name_len, char *value, int exp_env)
{
	t_env	*new_var;

	new_var = NULL;
		// fprintf(stderr, "IN SET VAR THE VAR NAME N VALUE IS-%s- AND -%s-\n",(name), value);
	if (!exp_env)
	{
		name = ft_strdup(name);
		value = ft_strdup(value);
	}
	if (!already_set(*env, name, name_len, value))
	{
		new_var = new_env_node(name, value);
		if (exp_env)
			add_in_lex_order(env, new_var);
		else
			add_back(env, new_var);
	}
		// fprintf(stderr, "IN SET VAR-%s-\n",((*env)->name));

}
