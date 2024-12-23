/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:59 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/23 00:07:30 by noam             ###   ########.fr       */
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

void	ft_handle_sigint(int sig)
{
	(void)sig;
	// if (glob.is_child)
		// return ;
	printf("\n");
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	global_exit_code = 130;
}

void	ft_handle_sigint_doc(int sig)
{
	(void)sig;
	// if (glob.is_child)
		// return ;
	// printf("-on HERE-\n");
    // write(1,"\n\0\0", 3);
    // write(1,"\0", 1);
	// printf("\n");
	rl_replace_line("", 1);
	rl_on_new_line();
    close(STDIN_FILENO);
	rl_redisplay();
    // printf("prompt:");
	global_exit_code = 130;
}

void	ft_handle_sigint_child(int sig)
{
	(void)sig;
		return ;
}

void	signal_handler(void)
{
    global_exit_code = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_handle_sigint);
	signal(SIGTSTP, SIG_IGN);
}
