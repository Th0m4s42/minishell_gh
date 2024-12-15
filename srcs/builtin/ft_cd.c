/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:44:49 by noam              #+#    #+#             */
/*   Updated: 2024/12/15 01:58:38 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	update_hiddn_pwds(t_shell *shell)
{
	if(shell->hiddn_oldpwd)
		free(shell->hiddn_oldpwd);
	if (shell->hiddn_pwd)
	{
		shell->hiddn_oldpwd = shell->hiddn_pwd;
		shell->hiddn_pwd = getcwd(NULL, 0);
	}
	else
		shell->hiddn_pwd = getcwd(NULL, 0);
}

void	update_env_pwds(t_env **env, t_shell *shell)
{
	char	*new_pwd;
	char	*new_old_pwd;
	char	*pwd;
	char	*oldpwd;
	
	new_pwd = ft_strdup(shell->hiddn_pwd);
	new_old_pwd = ft_strdup(shell->hiddn_oldpwd);
	pwd = ft_strdup("PWD");
	oldpwd = ft_strdup("OLDPWD");
	if (already_set(*env, pwd, 3, new_pwd))
	{
		if(!already_set(*env, oldpwd, 6, new_old_pwd))
		{
			free(oldpwd);
			free(new_old_pwd);
		}
	}
	else
	{
		free(pwd);
		free(oldpwd);
		free(new_pwd);
		free(new_old_pwd);
	}
}

static inline int	cd_err_message(char *path)
{
	struct stat path_state;
	lstat(path, &path_state);
	if (!S_ISDIR(path_state.st_mode))
	{
		ft_putstr_fd("minishell: cd:", STDERR);
		ft_putstr_fd(path, STDERR);
		ft_putendl_fd(": Not a directory", STDERR);
	}
	return (1);
}

int		go_to_home(char *home_path)
{
	if (!home_path)
	{
		ft_putendl_fd("minishell: cd: HOME not set", STDERR);
		return (1);
	}
	else if (chdir(home_path) == -1)
		return(cd_err_message(home_path));
	return (0);
}
		
int	ft_cd(char **cmd, t_shell *shell)
{
	int	ret;

	ret = 0;
	if (cmd[1] == NULL)
		return (go_to_home(get_value_by_name(shell->fallback_env, "HOME")));
	if (cmd[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", STDERR);
		return (1);
	}
	else if (chdir(cmd[1]) == -1)
		ret = cd_err_message(cmd[1]);
	if (ret == 0)
	{
		update_hiddn_pwds(shell);
		update_env_pwds(&shell->env, shell);
		update_env_pwds(&shell->fallback_env, shell);
	}
	return (ret);
}

// int	ft_cd(char **cmd, t_shell *shell)
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