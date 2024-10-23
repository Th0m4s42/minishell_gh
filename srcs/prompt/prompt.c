/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:23 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/23 16:04:10 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	get_id(t_env *env, t_prompt *info)
{
	char	*user;

	user = get_value_by_name(env, "USER");
	if (user == NULL || ft_strlen(user) > 41)
		ft_strlcpy(info->id, "user", 5);
	else
		ft_strlcpy(info->id, user, ft_strlen(user) + 1);
}

void	get_location(t_env *env, t_prompt *info)
{
	char	*session_manager;
	int		i;
	int		j;

	session_manager = get_value_by_name(env, "SESSION_MANAGER");
	if (session_manager == NULL)
	{
		ft_strlcpy(info->hostname, "session_manager", 16);
		return ;
	}
	i = 0;
	while (session_manager[i] != '/' && session_manager[i])
		i++;
	i++;
	j = i;
	while (session_manager[j] != '.' && session_manager[j])
		j++;
	if (j - i + 1 > 42)
		ft_strlcpy(info->hostname, "session_manager", 16);
	else
		ft_strlcpy(info->hostname, &session_manager[i], j - i + 1);
}

void	get_pwd(t_prompt *info)
{
	if (getcwd(info->pwd, 420) == NULL)
		ft_strlcpy(info->pwd, "here", 5);
}

void	concat_prompt(t_prompt *info)
{
	info->prompt[0] = '\0';
	ft_strlcat(info->prompt, info->id, sizeof(info->prompt));
	ft_strlcat(info->prompt, "@", sizeof(info->prompt));
	ft_strlcat(info->prompt, info->hostname, sizeof(info->prompt));
	ft_strlcat(info->prompt, ":~", sizeof(info->prompt));
	ft_strlcat(info->prompt, info->pwd, sizeof(info->prompt));
	ft_strlcat(info->prompt, "👾 ", sizeof(info->prompt));
}

void	get_info(t_env *env, t_prompt *info)
{
	get_id(env, info);
	get_location(env, info);
	get_pwd(info);
	concat_prompt(info);
}
