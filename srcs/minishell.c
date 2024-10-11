/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/11 16:24:48 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char *rl_value;
	t_env *env;

	(void)argv;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp);
	while (env)
	{
		printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	printf("------\n");
	free_env_list(&env);
	// while (1)
	// {
	// 	rl_value = readline("minishell:");
	// 	add_history(rl_value);
	// 	free(rl_value);
	// }
	return (0);
}
