/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/09 17:57:26 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char *rl_value;

	(void)argv;
	(void)envp;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	while (1)
	{
		rl_value = readline("minishell:");
		add_history(rl_value);
		free(rl_value);
	}
	return (0);
}
