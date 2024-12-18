/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:44:17 by noam              #+#    #+#             */
/*   Updated: 2024/12/14 19:57:13 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exec_built_in(char **cmd, t_env *env, t_shell *shell)
{
	(void)env;
	if (!ft_strncmp(cmd[0], "echo", 5))
		ft_echo(cmd, shell);
	else if (!ft_strncmp(cmd[0], "cd", 3))
		ft_cd(cmd, shell);
	else if (!ft_strncmp(cmd[0], "pwd", 4))
		ft_pwd();
	else if (!ft_strncmp(cmd[0], "export", 7))
		ft_export(cmd, shell);
	else if (!ft_strncmp(cmd[0], "unset", 6))
		ft_unset(cmd, shell);
	else if (!ft_strncmp(cmd[0], "env", 4))
		ft_env(shell->env);
	else if (!ft_strncmp(cmd[0], "exit", 5))
		ft_exit(cmd, shell);
}
