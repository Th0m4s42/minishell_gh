/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:30:03 by noam              #+#    #+#             */
/*   Updated: 2024/12/22 02:06:21 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_env(t_env *env)
{
	t_env	*var;

	var = env;
	while (var)
	{
		if (var->value)
		{
			ft_putstr_fd(var->name, STDOUT);
			write(1, "=", 1);
			ft_putstr_fd(var->value, STDOUT);
			write(1, "\n", 1);
		}
		var = var->next;
	}
	return (0);
}
