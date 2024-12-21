/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:59 by thbasse           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/21 13:23:48 by noam             ###   ########.fr       */
=======
/*   Updated: 2024/12/19 15:02:43 by thbasse          ###   ########.fr       */
>>>>>>> 1816e5cb6ef70496e6cba58d8509000e2517a299
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
<<<<<<< HEAD

void    ft_handle_sigint(int sig)
{
    (void)sig;
    if (glob.is_child)
        return ;
    printf("\n");
    // printf("\n");
    rl_replace_line("", 1);
    rl_on_new_line();
    rl_redisplay();
    glob.exit_code = 130;
}

void    signal_handler(void)
{
    glob.is_child = 0;
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, ft_handle_sigint);
    signal(SIGTSTP, SIG_IGN);
}
=======
>>>>>>> 1816e5cb6ef70496e6cba58d8509000e2517a299
