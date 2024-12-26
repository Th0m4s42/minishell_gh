/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_cmd_or_dir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 00:30:59 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 02:39:29 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

static void	error_builder(char *arg, char *err_mess)
{
	ft_putstr_fd(arg, STDERR);
	ft_putendl_fd(err_mess, STDERR);
}

/* ************************************************************************** */

int	check_for_the_cmd(char *path, char *cmd)
{
	struct stat	path_stat;

	if (!path || access(path, F_OK) != 0)
	{
		error_builder(cmd, ": command not found");
		return (127);
	}
	if (stat(path, &path_stat) != 0)
		return (127);
	if (S_ISDIR(path_stat.st_mode))
	{
		error_builder(cmd, ": Is a directory");
		return (126);
	}
	if (access(path, X_OK) != 0)
	{
		ft_putstr_fd("minishell :", STDERR);
		error_builder(cmd, ": Permission denied");
		return (126);
	}
	return (0);
}

/* ************************************************************************** */
