/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/16 15:19:16 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	//char		*rl_value;
	t_env		*env;
	t_prompt	prompt_info;
	char		*line = "d/u fun \'pour toi\'du fun\"pour |moi\" cmd1 || cmd2 <input>> output |cmd";
	t_token		*tok = lexer(line);

	(void)argv;
	//rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp); //a proteger
	get_info(env, &prompt_info);

	// test de la tokenisation

	while (tok)
	{
		printf("token type:%d value:%s\n", tok->type, tok->value);
		tok = tok->next;
	}
	free(tok);
	free_env_list(&env);
	// while (1)
	// {
	// 	rl_value = readline(prompt_info.prompt);
	// 	if (rl_value == NULL)
	// 		break ;
	// 	add_history(rl_value);
	// 	free(rl_value);
	// }
	// return (0);
}

	// to do before exit:
	// free_env_list(&env);
	// clear_history();