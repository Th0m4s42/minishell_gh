/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/11 15:07:41 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char *rl_value;
	t_env *env = NULL;

	(void)argv;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	get_env(envp);
	while (envp)
	{
		printf("%s=%s", env->name, env->value);
		envp++;
	}
	free_env_list(&env);
	// while (1)
	// {
	// 	rl_value = readline("minishell:");
	// 	add_history(rl_value);
	// 	free(rl_value);
	// }
	return (0);
}
