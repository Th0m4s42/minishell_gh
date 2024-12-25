/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:33:29 by noam              #+#    #+#             */
/*   Updated: 2024/12/25 16:02:01 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_resources(t_shell *shell, char **cmd)
{
	ft_free_tab(cmd);
	free_tok_list(&shell->start);
	cleanup_shell(shell);
	clear_history();
}

int	handle_exit_code(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": numeric argument required", 2);
			return (255);
		}
		i++;
	}
	return (ft_atoi(arg) % 256);
}

void	real_exit(int ret, t_shell *shell, char **cmd)
{
	free_resources(shell, cmd);
	exit(ret);
}

int	ft_exit(char **cmd, t_shell *shell)
{
	int	ret;

	ret = 0;
	if (cmd[1])
	{
		if (cmd[2])
		{
			ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
			return (1);
		}
		ret = handle_exit_code(cmd[1]);
		real_exit(ret, shell, cmd);
	}
	real_exit(ret, shell, cmd);
	return (ret);
}

// int	ft_exit(char **cmd, t_shell *shell)
// {
// 	int	ret;
// 
// 	ret = 0;
// 	if (cmd[1])
// 	{
// 		if (cmd[2])
// 		{
// 			ft_putendl_fd("exit: too many arguments", STDERR);
// 			return (1);
// 		}
// 		ret = ft_atoi(cmd[1]) % 256;
// 		ft_free_tab(cmd);
// 		free_tok_list(&shell->start);
// 		free_env_list(&shell->env);
// 		free_env_list(&shell->fallback_env);
// 		clear_history();
// 		exit(ret);
// 	}
// 	ft_free_tab(cmd);
// 	free_tok_list(&shell->start);
// 	free_env_list(&shell->env);
// 	free_env_list(&shell->fallback_env);
// 	clear_history();
// 	exit(ret);
// 	return (ret);
// }
