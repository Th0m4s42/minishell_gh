/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:25:49 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/10 15:58:55 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_env(t_env *save, char **envp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=')
			j++;
		save->name = malloc(sizeof(char) * (j + 1));
		ft_strlcpy(save->name, envp[i], j);
		k = j;
		while (envp[i][k] != '\0')
			k++;
		save->value = malloc(sizeof(char) * (k - j + 1));
		ft_strlcpy(save->value, *(envp + j), k - j);
		new_env_node(save->name, save->value);
		i++;
	}
	return (1);
}
