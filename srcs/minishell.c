/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/24 12:55:05 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char		*rl_value;
	t_env		*env;
	t_prompt	prompt_info;
	char		**tok;
	int			index;

	(void)argv;
	index = 0;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp);
	get_info(env, &prompt_info);
	while (1)
	{
		rl_value = readline(prompt_info.prompt);
		if (rl_value == NULL)
			break ;
		add_history(rl_value);
		tok = ft_strtok(rl_value, " <>\'\"|");
		while (tok)
		{
			printf("token: %s\n", tok[index]);
			index++;
		}
		free(rl_value);
	}
	return (0);
}

	// to do before exit:
	// free_env_list(&env);
	// clear_history();