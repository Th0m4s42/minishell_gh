/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:44:17 by noam              #+#    #+#             */
/*   Updated: 2024/12/06 01:06:07 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	exec_built_in(char **cmd, t_env *env, t_shell *shell)
{
	(void)env;
	// if (!ft_strncmp(cmd[0], "echo", 5))
	// 	ft_echo(cmd);
	// else if (!ft_strncmp(cmd[0], "cd", 3))
	// 	ft_cd(cmd, env);
	// else 
	if (!ft_strncmp(cmd[0], "pwd", 4))
		ft_pwd();
// 	else if (!ft_strncmp(cmd[0], "export", 7))
// 		ft_export(cmd, env);
// 	else if (!ft_strncmp(cmd[0], "unset", 6))
// 		ft_unset(cmd, env);
// 	else if (!ft_strncmp(cmd[0], "env", 4))
// 		ft_env(env);
	else if (!ft_strncmp(cmd[0], "exit", 5))
		ft_exit(cmd, shell);
}
