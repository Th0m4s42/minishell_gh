/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:44:49 by noam              #+#    #+#             */
/*   Updated: 2024/12/04 17:14:17 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// void	update_pwds(t_env *env, t_env *fallback_env)
// {
// 	char	new_pwd;
// 	char	old_pwd;
	
// 	old_pwd = get_value_by_name(env, "PATH");
// 	new_pwd = getcwd(NULL, 0);
// 	if (!new_pwd)
// 	{
// 		perror("minishell: ");
// 		return ;
// 	}
// 	else
		 
// }


// int	ft_cd(char **cmd, t_env *env)
// {
// 	int	ret;

// 	ret = 0;
// 	if (cmd[1] == NULL)
// 		ret = go_to_home(env);
// 	else if (cmd[2])
// 	{
// 		ft_putendl_fd("cd: too many arguments", STDERR);
// 		return (1);
// 	}
// 	else if (cmd[1][0] == "-")
// 		ret = go_to_previous(env);
// 	else if (chdir(cmd[1]) == -1)
// 	{
// 		perror("minishell: cd: ");
// 		ret = errno;
// 	}
// 	if (ret == 0)
// 	{
// 		update_pwds(env);
// 		update_oldpwd(env);
// 	}
// 	return (ret);
// }

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