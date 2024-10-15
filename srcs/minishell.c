/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/15 18:28:51 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	*rl_value;
	t_env	*env;
	t_prompt	*prompt_info;
	// t_env	*tmp;

	(void)argv;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp);
	prompt_info = get_info(env);
	// tmp = env;
	// iter_shlvl(tmp);
	// while (tmp)
	// {
	// 	printf("%s=%s\n", tmp->name, tmp->value);
	// 	tmp = tmp->next;
	// }
	// free_env_list(&env);
	while (1)
	{
		rl_value = readline(display_prompt(prompt_info));
		if (rl_value == NULL)
			break ;
		add_history(rl_value);
		free(rl_value);
	}
	return (0);
}
