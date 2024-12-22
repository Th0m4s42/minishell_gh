/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:33:29 by noam              #+#    #+#             */
/*   Updated: 2024/12/22 02:05:59 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_exit(char **cmd, t_shell *shell)
{
	int	ret;

	ret = 0;
	if (cmd[1])
	{
		if (cmd[2])
		{
			ft_putendl_fd("exit: too many arguments", STDERR);
			return (1);
		}
		ret = ft_atoi(cmd[1]) % 256;
		ft_free_tab(cmd);
		free_tok_list(&shell->start);
		free_env_list(&shell->env);
		exit(ret);
	}
	ft_free_tab(cmd);
	free_tok_list(&shell->start);
	free_env_list(&shell->env);
	exit(ret);
}
