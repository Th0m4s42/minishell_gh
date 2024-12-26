/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:09:59 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 12:13:06 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

void	ft_handle_sigquit(int sig_num)
{
	ft_putstr_fd("Quit: \n", 2);
	g_lobal_exit_code = sig_num;
}

/* ************************************************************************** */

void	ft_handle_sigquit_doc(int sig_num)
{
	rl_replace_line("", 1);
	rl_on_new_line();
	close(STDIN_FILENO);
	rl_redisplay();
	ft_putstr_fd("Quit: \n", 2);
	g_lobal_exit_code = sig_num;
}

/* ************************************************************************** */