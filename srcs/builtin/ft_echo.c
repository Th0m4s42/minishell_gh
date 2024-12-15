/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:55:58 by noam              #+#    #+#             */
/*   Updated: 2024/12/15 01:58:51 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_echo(char **cmd_arg, t_shell *shell)
{
	int		i;
	int		new_l;

	((void)shell);
	i = 0;
	new_l = 1;
	if (cmd_arg[1])
	{
		if (!ft_strncmp(cmd_arg[1], "-n", 2))
		{
			new_l = 0;
			i++;
		}
		// fprintf(stderr, "new_line -%d-\ni -%d-\n", new_l, i);
		while(cmd_arg[++i])
			ft_putstr_fd(cmd_arg[i], STDOUT);
	}
	if (new_l)
		write(1, "\n", 1);
	return(0);
}