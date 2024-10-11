/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/11 18:16:50 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	*rl_value;
	t_env	*env;
	t_env	*tmp;

	(void)argv;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp);
	
	tmp = env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
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
