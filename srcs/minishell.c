/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/06 15:15:49 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char		*rl_value;
	t_env		*env;
	t_prompt	prompt_info;
	// char		*line = "du fun \'pour toi\'du fun\"pour |moi\"";
	// char		**tok = ft_strtok(line, " |\t\\<>");
	// int			i = 0;

	(void)argv;
	rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp);
	get_info(env, &prompt_info);

	// test de la tokenisation

	// while (tok[i])
	// {
	// 	printf("token: %s\n", tok[i]);
	// 	free(tok[i]);
	// 	i++;
	// }
	// free(tok);
	// free_env_list(&env);
	while (1)
	{
		rl_value = readline(prompt_info.prompt);
		if (rl_value == NULL)
			break ;
		add_history(rl_value);
		//lexer(rl_value);
		free(rl_value);
	}
	return (0);
}

	// to do before exit:
	// free_env_list(&env);
	// clear_history();