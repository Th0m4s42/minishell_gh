/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:23 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/12 17:51:23 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_id(t_env *env)
{
	t_env	*temp;
	char	*id;

	id = NULL;
	if (env == NULL)
		return ("user");
	temp = env;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "USER", 4) == 0)
		{
			id = ft_strdup(temp->value);
			break ;
		}
		temp = temp->next;
	}
	return (id);
}

char	*get_location(t_env *env)
{
	t_env	*temp;
	char	*loc;

	loc = NULL;
	if (env == NULL)
		return ("somewhere");
	temp = env;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "SESSION_MANAGER", 15) == 0)
		{
			loc = ft_substr(temp->value, 6, 13);
			break ;
		}
		temp = temp->next;
	}
	return (loc);
}

char	*get_pwd(t_env *env)
{
	t_env	*temp;
	char	*pwd;

	pwd = NULL;
	if (env == NULL)
		return ("home");
	temp = env;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->name, "PWD", 3) == 0)
		{
			pwd = ft_strdup(temp->value);
			break ;
		}
		temp = temp->next;
	}
	return (pwd);
}

t_prompt	*get_info(t_env *env)
{
	t_prompt	*prompt_info;

	prompt_info = malloc(sizeof(t_prompt));
	prompt_info->id = get_id(env);
	prompt_info->location = get_location(env);
	prompt_info->pwd = get_pwd(env);
	return (prompt_info);
}

// dispaly_prompt(t_prompt *prompt_info)
// prompt_info->id@prompt_info->location:~/prompt_info->pwd$ 
// et merde

char	*display_prompt(t_prompt *prompt_info)
{
	char	*prompt_line;

	prompt_line = ft_strdup(prompt_info->id);
	prompt_line = ft_strjoin(prompt_line, "@");
	prompt_line = ft_strjoin(prompt_line, prompt_info->location);
	prompt_line = ft_strjoin(prompt_line, "~");
	prompt_line = ft_strjoin(prompt_line, prompt_info->pwd);
	prompt_line = ft_strjoin(prompt_line, "$ ");
	return (prompt_line);
}
