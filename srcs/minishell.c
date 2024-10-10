/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/10 15:50:40 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char *rl_value;
	t_env *env;

	(void)argv;
	env = malloc(sizeof(t_env));
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	get_env(env, envp);
	while(env)
	{
		printf("%s = %s\n ", env->name, env->value);
		env = env->next;
	}
	// while (1)
	// {
	// 	rl_value = readline("minishell:");
	// 	add_history(rl_value);
	// 	free(rl_value);
	// }
	return (0);
}
