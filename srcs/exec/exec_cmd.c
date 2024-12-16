/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:26:25 by noam              #+#    #+#             */
/*   Updated: 2024/12/13 18:59:24 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

char	**env_to_array(t_env *env)
{
	char	**env_array;
	t_env	*tmp;
	char 	*tmp_str;
	int		i;

	i = 0;
	tmp = env;
	tmp_str = NULL;
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
		tmp_str = ft_strjoin(tmp->name, "=");
		env_array[i] = ft_strjoin_free(tmp_str, tmp->value, 1);
		// free(tmp_str);
		// env_array[i] = ft_strjoin(tmp->name, tmp->value);
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

	tmp = ft_strjoin(path, "/");
	cmd_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (cmd_path);
}

void	printcmd(char **cmd_arg, char *path, char **env_array)
{
	int	i;

	i = 0;
	((void)env_array);
	fprintf(stderr,"cmd: %s\n", path);
	while (cmd_arg[i])
	{
		fprintf(stderr,"arg[%d]: %s\n", i, cmd_arg[i]);
		i++;
	}
	i = 0;
	// while (env_array[i])
	// {
	// 	printf("env[%d]: %s\n", i, env_array[i]);
	// 	i++;
	// }
}

void	print_env_array(char **array)
{
	int i = 0;
	// int j = 0;
	if (!array)
	{
		fprintf(stderr, "++\n");
		return;
	}
	while (array[i])
	{
		fprintf(stderr, "-----%s\n", array[i]);
		i++;
	}
	fprintf(stderr, "++\n");
}

int	process_cmd(char **cmd_arg, char *path, t_env *env)
{
	char	**env_array;
	int		pid;
	int		ret;

	env_array = env_to_array(env);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd_arg[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_tab(env_array);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		ret = execve(path, cmd_arg, env_array);
		ft_putstr_fd("minishell: ", 2);
		perror(cmd_arg[0]);
		exit(126);
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
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_free_tab(bin_paths);
	return (NULL);
}


void	exec_bin(char **cmd_arg, t_env *env)
{
	char	*path;
	// int		ret;

	path = NULL;
	if (cmd_arg && has_backslash(cmd_arg[0]))
	{
		path = cmd_arg[0];
		cmd_arg[0] = ft_substr(ft_strrchr(cmd_arg[0], '/'), 1 , ft_strlen(ft_strrchr(cmd_arg[0], '/')));
	}
	else if (cmd_arg)
		path = find_exec_path(cmd_arg[0], env);
	// printcmd(cmd_arg, path, NULL);
	/*ret = */process_cmd(cmd_arg, path, env);
	// fprintf(stderr, "path = %s : cmd_arg = %s\n", path, cmd_arg[0]);	
	if (path)
		free(path);

}