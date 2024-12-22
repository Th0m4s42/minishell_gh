/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:55:58 by noam              #+#    #+#             */
/*   Updated: 2024/12/21 23:29:48 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_echo(char **cmd_arg, t_shell *shell)
{
	int		i;
	int		new_l;

	((void)shell);
	i = 0;
	new_l = 0;
	if (cmd_arg[1])
	{
		new_l = ft_strncmp(cmd_arg[1], "-n", 2);
		if (new_l == 0)
			i++;
		while (cmd_arg[++i])
		{
			ft_putstr_fd(cmd_arg[i], STDOUT);
			if (cmd_arg[i + 1])
				write(1, " ", 1);
		}
	}
	if (new_l != 0)
		write(1, "\n", 1);
	return (0);
}
