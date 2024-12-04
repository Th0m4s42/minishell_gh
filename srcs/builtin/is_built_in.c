/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:35:15 by noam              #+#    #+#             */
/*   Updated: 2024/12/03 22:53:15 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	is_built_in(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 5))
		return (true);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (true);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (true);
	else if (!ft_strncmp(cmd, "export", 7))
		return (true);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (true);
	else if (!ft_strncmp(cmd, "env", 4))
		return (true);
	else if (!ft_strncmp(cmd, "exit", 5))
		return (true);
	else
		return (false);
}
//bash has a fallback for some env variables
// after unsetting PWD or OLDPWD
//	cd will update PWD to the coressponding dir
//	echo $PWD works after 1 cd call
//	echo $OLDPWD works after 1 cd call if fallback $PWD present
// but env won't show PWD OLDPWD,
// exporting var will show them in env again,
// and they will be updated by cd
