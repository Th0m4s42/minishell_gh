/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:44:17 by noam              #+#    #+#             */
/*   Updated: 2024/12/22 02:05:13 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	exec_built_in(char **cmd, t_env *env, t_shell *shell)
{
	(void)env;
	if (!ft_strncmp(cmd[0], "exit", 5))
		return (ft_exit(cmd, shell));
	else if (!ft_strncmp(cmd[0], "echo", 5))
		return (ft_echo(cmd, shell));
	else if (!ft_strncmp(cmd[0], "cd", 3))
		return (ft_cd(cmd, shell));
	else if (!ft_strncmp(cmd[0], "pwd", 4))
		return (ft_pwd());
	else if (!ft_strncmp(cmd[0], "export", 7))
		return (ft_export(cmd, shell));
	else if (!ft_strncmp(cmd[0], "unset", 6))
		return (ft_unset(cmd, shell));
	else if (!ft_strncmp(cmd[0], "env", 4))
		return (ft_env(shell->env));
	else
		return (1);
}

