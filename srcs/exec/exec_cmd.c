/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:26:25 by noam              #+#    #+#             */
/*   Updated: 2024/11/21 22:10:28 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <env.h>
#include <libft.h>

/* ************************************************************************** */

char	**env_to_array(t_env *env)
{
	char	**env_array;
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	env_array = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = env;
	while (tmp)
	{
		env_array[i] = ft_strjoin(tmp->name, tmp->value);
		i++;
		tmp = tmp->next;
	}
	env_array[i] = NULL;
	return (env_array);
}

char	*bin_cmd_path(const char *path, const char *cmd)
{
	char	*tmp;
	char	*cmd_path;

	tmp = ft_strjoin(path, '/');
	path = ft_strjoin(tmp, cmd);
	free(tmp);
}

int	process_cmd(char **cmd_arg, char *path, t_env *env,t_shell *shell)
{
	char **env_array;
	int 	pid;
	int 	ret;

	env_array = env_to_array(env);
	pid = fork();
	if (pid == 0)
	{
		ret = execve(path, cmd_arg, env_array);
		perror("minishell");
		exit(ret);
	}
	else
		waitpid(pid, &ret, 0);
	ft_free_tab(env_array);
	return (ret);
		
}


/* ************************************************************************** */

char 	*find_exec_path(const char *cmd_name, t_env *env)
{
	char	**bin_paths;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd_path = NULL;
	bin_paths = ft_split(get_value_by_name(env, "PATH"), ':');
	while (bin_paths && bin_paths[i])
	{
		cmd_path = bin_cmd_path(bin_paths[i], cmd_name);
		if (!access(cmd_path, F_OK | X_OK))
		{
			ft_free_tab(bin_paths);
			return(cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_tab(bin_paths);
	return (NULL);
}


void	exec_bin(char **cmd_arg, t_env *env, t_shell *shell)
{
	char	*path;
	int		ret;

	// if (cmd_arg && has_backslash(cmd_arg[0]))
	// 	path = cmd_arg[0];
	/*else */if (cmd_arg)
		path = find_exec_path(cmd_arg[0], env);
	ret = process_cmd(cmd_arg, path, env, shell);	
}