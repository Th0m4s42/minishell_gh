/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:59 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/19 15:02:43 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	sign_handler(int sig_num)
{
	(void) sig_num;
	if (sig_num == SIGINT)
	{
		ft_putstr_fd("\n", 1);
	}
	if (sig_num == SIGQUIT)
	{
		ft_putstr_fd("Quit: \n", 1);
	}
}
