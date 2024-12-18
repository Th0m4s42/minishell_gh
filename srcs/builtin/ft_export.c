/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:06:45 by noam              #+#    #+#             */
/*   Updated: 2024/12/16 14:02:02 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void add_in_lex_order(t_env **first, t_env *new_var)
{
    t_env *tmp;
    t_env *current_var;
    char *var_name;

    var_name = new_var->name;
    // if (*first == NULL || ft_strncmp(var_name, (*first)->name, ft_strlen(var_name)) < 0) {
    if (*first == NULL || (ft_strncmp(var_name, (*first)->name, INT_MAX) < 0))
	{
		// fprintf(stderr, "flipfront=%s=\n",new_var->name);
        new_var->next = *first;
        *first = new_var;
		// fprintf(stderr, "abckflip-%s-\n",(*first)->name);
        return;
    }
    tmp = *first;
    current_var = (*first)->next;
    while (current_var != NULL && ft_strncmp(var_name, current_var->name, INT_MAX) >= 0)
	{
        tmp = current_var;
        current_var = current_var->next;
    }
	if (!current_var)
		tmp->next = new_var;
	else
	{
		tmp->next = new_var;
		new_var->next = current_var;
	}
}

/* ************************************************************************** */

static inline int	export_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR);
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd("': not a valid identifier", STDERR);
	return (1);
}

/* ************************************************************************** */


/* ************************************************************************** */

int	ft_exp_displ(t_env *env)
{
	t_env	*var;

	var = env;
	// fprintf(stderr, "uhhh%s= \n", var->name);
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

int	ft_export(char **cmd, t_shell *shell)
{
	char	*var_name;
	int		name_len;
	char 	*var_value;
	int		i;

	var_name = NULL;
	var_value = NULL;
	name_len = 0;
	i = 1;
	if (!cmd[i])
		return (ft_exp_displ(shell->fallback_env));
	while(cmd[i])
	{
		var_value = ft_strchr(cmd[i], '=');
		if (var_value && ft_strlen(var_value) == ft_strlen(cmd[i]))
			return (export_error(cmd[i]));
		name_len = ft_strlen(cmd[i]) - ft_strlen(var_value);
		if (!var_value)
		{
			set_var(&shell->env, ft_strdup(cmd[i]), name_len, NULL, 1);
			set_var(&shell->fallback_env, ft_strdup(cmd[i]), name_len, NULL, 1);
		}
		else
		{
			var_name = ft_substr(cmd[i], 0, name_len);
			var_value = ft_strdup(var_value + 1);
			set_var(&shell->env, var_name, name_len, var_value, 0);
			set_var(&shell->fallback_env, var_name, name_len, var_value, 1);
		}
		i++;
	}
	return(0);
}
/* ************************************************************************** */



// 			if (var_exist(env, cmd[i], var_name_len) && ft_strlen(tmp) > 0)
// 			{
// 				// replace_var_value(shell->env, ft_substr(cmd[i], 0, (ft_strlen(cmd[i]) - ft_strlen(tmp)))), 
// 				replace_var_value(shell->env, ft_strdup(tmp + 1), );
// 				replace_var_value(shell->fallback_env, ft_strdup(tmp + 1), );
// 				// replace_var_value(shell->fallback_env, ft_substr(cmd[i], 0, (ft_strlen(cmd[i]) - ft_strlen(tmp)))), 
// 			}
// 			else if (ft_strlen(tmp) > 0)
// 			{
// 				new_var = new_env_node(ft_substr(cmd[i], 0, (ft_strlen(cmd[i]) - ft_strlen(tmp))), ft_strdup(tmp + 1));
// 				add_back(&(shell->env), new_var);
// 				new_var = new_env_node(ft_substr(cmd[i], 0, (ft_strlen(cmd[i]) - ft_strlen(tmp))), ft_strdup(tmp + 1));
// 				add_in_lex_order(&(shell)->fallback_env, new_var);
// 			}
// 			else 
// 			{
// 				new_var = new_env_node(ft_strdup(cmd[i]), NULL);
// 				add_in_lex_order(&(shell)->fallback_env, new_var);
// 			}
// 			i++;
// 			// tmp = NULL;
// 		}
// 	}
// }



/* ************************************************************************** */

//so first we should,
/*
	look at if 
		export has arg, if not , print_fallback_env
		return;

	while (arg)
	// if arg
		then var_name, name_len and var_value and 
	if strncmp var_val var_name
		print_error
		return;
	if arg !has_char('=')
		only in export
		set_var(var_name, var_name_len, var_value
			if (!var_value_switch(var_name, name_len, var_value)
			add_in_lex_order(&(shell)->fallback_env,new_env_node())
	else 
		set_var(fallbackenv)
		set_var(env)

*/