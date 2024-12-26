/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:06:45 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 00:15:24 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	add_in_lex_order(t_env **first, t_env *new_var)
{
	t_env	*tmp;
	t_env	*curr;
	char	*var_name;

	var_name = new_var->name;
	if (*first == NULL || (ft_strncmp(var_name, (*first)->name, INT_MAX) < 0))
	{
		new_var->next = *first;
		*first = new_var;
		return ;
	}
	tmp = *first;
	curr = (*first)->next;
	while (curr != NULL && ft_strncmp(var_name, curr->name, INT_MAX) >= 0)
	{
		tmp = curr;
		curr = curr->next;
	}
	if (!curr)
		tmp->next = new_var;
	else
	{
		tmp->next = new_var;
		new_var->next = curr;
	}
}

/* ************************************************************************** */

static inline int	export_error(char *arg, int free_arg)
{
	ft_putstr_fd("minishell: export: `", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
	if (free_arg)
		free(arg);
	return (1);
}

/* ************************************************************************** */

int	ft_exp_displ(t_env *env)
{
	t_env	*var;

	var = env;
	if (!var)
		return (1);
	while (var)
	{
		write(1, "declare -x ", 11);
		ft_putstr_fd(var->name, STDOUT);
		if (var->value)
		{
			write(1, "=", 1);
			write(1, "\"", 1);
			ft_putstr_fd(var->value, STDOUT);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		var = var->next;
	}
	return (0);
}

/* ************************************************************************** */

void	add_var_to_list(t_shell *shell, char *name, char *value)
{
	if (!value)
	{
		set_var(&shell->env, ft_strdup(name), NULL, 1);
		set_var(&shell->fallback_env, ft_strdup(name), NULL, 1);
	}
	else
	{
		set_var(&shell->env, name, value, 0);
		set_var(&shell->fallback_env, ft_strdup(name), value, 1);
	}
}

int	ft_export(char **cmd, t_shell *shell)
{
	char	*var_name;
	char	*var_value;
	int		i;

	i = 1;
	if (!cmd[i])
		return (ft_exp_displ(shell->fallback_env));
	while (cmd[i])
	{
		var_value = ft_strchr(cmd[i], '=');
		if (var_value && ft_strlen(var_value) == ft_strlen(cmd[i]))
			return (export_error(cmd[i], 0));
		var_name = make_var_name(cmd[i], ft_strlen(var_value));
		if (isnt_alnum(var_name))
			return (export_error(var_name, 1));
		if (!var_value)
			add_var_to_list(shell, var_name, NULL);
		else
			add_var_to_list(shell, var_name, ft_strdup(var_value + 1));
		free(var_name);
		i++;
	}
	return (0);
}
