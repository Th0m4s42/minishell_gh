/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:18:59 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/26 12:10:45 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

void	ft_handle_sigint(int sig)
{
	write(2, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_lobal_exit_code = sig;
}

/* ************************************************************************** */

void	ft_handle_sigint_doc(int sig)
{
	rl_replace_line("", 1);
	rl_on_new_line();
	close(STDIN_FILENO);
	rl_redisplay();
	g_lobal_exit_code = sig;
}

/* ************************************************************************** */

void	ft_handle_sigint_child(int sig)
{
	g_lobal_exit_code = sig;
	return ;
}

/* ************************************************************************** */

void	signal_handler(void)
{
	g_lobal_exit_code = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_handle_sigint);
	signal(SIGTSTP, SIG_IGN);
}

/* ************************************************************************** */
