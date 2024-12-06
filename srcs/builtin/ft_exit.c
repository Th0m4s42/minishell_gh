/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:33:29 by noam              #+#    #+#             */
/*   Updated: 2024/12/06 00:35:02 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exit(char **cmd, t_env *env)
{
	(void)env;
	if (cmd[1])
	{
		if (cmd[2])
		{
			ft_putendl_fd("exit: too many arguments", STDERR);
			return ;
		}
		exit(ft_atoi(cmd[1]));
	}
	exit(0);
}
