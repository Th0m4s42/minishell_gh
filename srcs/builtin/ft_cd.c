/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:44:49 by noam              #+#    #+#             */
/*   Updated: 2024/12/04 14:39:12 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// void	ft_cd(char **cmd, t_env *env)
// {
	// (void)env;
	// (void)cmd;

	// if (cmd[1] == NULL)
		// go to home
		// if (chdir(get_value_by_name(env, "HOME")) == -1)
			// error minishell: cd: HOME not set
			// exit
	// else if (cmd[2])
		// error too many arguments
		// exit
	// else if (cmd[1] == "-")
		// go to previous directory OLDPWD
			// if OLDPWD is not set
				// error
				// exit
		// n write path "~/Desktop/....."
	// else if (chdir(cmd[1]) == -1)
		// perror
		// exit
	// update env (if there)
		// update oldpwd with current pwd (if there)
		// update pwd with new pwd (with getcwd)
		//
// }