/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:02:14 by noam              #+#    #+#             */
/*   Updated: 2024/12/21 23:31:24 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static inline void	free_node(t_env *node)
{
	if (!node)
		return ;
	if (node->name)
		free(node->name);
	if (node->value)
		free(node->value);
	free(node);
}

void	del_var(t_env **env, char *var)
{
	t_env	*tmp;
	t_env	*current_var;
	int		var_len;

	var_len = ft_strlen(var) + 1;
	tmp = *env;
	if (*env == NULL || ft_strncmp(var, (*env)->name, var_len) == 0)
	{
		*env = (*env)->next;
		free_node(tmp);
		return ;
	}
	current_var = (*env)->next;
	while (current_var)
	{
		if (ft_strncmp(var, current_var->name, var_len) == 0)
		{
			tmp->next = current_var->next;
			free_node(current_var);
			current_var = tmp->next;
			return ;
		}
		tmp = current_var;
		current_var = current_var->next;
	}
}

int	ft_unset(char **cmd, t_shell *shell)
{
	int	i;

	i = 1;
	if (cmd[1])
	{
		while (cmd[i])
		{
			if (!ft_strncmp(cmd[i], "PWD", 3))
			{
				free(shell->hiddn_pwd);
				shell->hiddn_pwd = NULL;
			}
			if (!ft_strncmp(cmd[i], "OLDPWD", 6))
			{
				free(shell->hiddn_oldpwd);
				shell->hiddn_oldpwd = NULL;
			}
			del_var(&(shell)->fallback_env, cmd[i]);
			del_var(&(shell)->env, cmd[i]);
			i++;
		}
	}
	return (0);
}
