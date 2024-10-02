/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/02 16:47:03 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	char *rl_value;
	
	rl_value = NULL;
	while (1)
	{
		rl_value = readline("minishell:");
		add_history(rl_value);
		free(rl_value);
	}
}
