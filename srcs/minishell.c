/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/06 11:40:02 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char *d_to_str(char **array)
{
	char *new_str = NULL;
	int i = 1;
	while (array[i])
	{
		new_str = ft_strjoin_free(new_str, array[i], 1);
		i++;
	}
	return (new_str);
}


static void one_liner(char **av, char **envp)
{
	char		*str;
	t_shell		shell;
	t_token		*tok;

	str = d_to_str(av);
	fprintf(stderr, "\n%s\n",str);
	init_shell(&shell, envp);
	tok = lexer(str);
	tok = add_end_tok(tok);
	shell.start = tok;
	exec(&shell);
	free_tok_list(&shell.start);
	free_env_list(&shell.env);
	free_env_list(&shell.fallback_env);
	free(str);



}


int	main(int argc, char **argv, char **envp)
{
	if (argc > 1)
		one_liner(argv,envp);
	char		*rl_value;
	// t_env		*env;
	t_prompt	prompt_info;
	t_shell		shell;
	t_token		*tok;

	(void)argv;
	rl_value = NULL;
	tok = NULL;
 	if (argc != 1)
		return (EXIT_FAILURE);
	init_shell(&shell, envp); 
	// env = get_env(envp); //a proteger
	get_info(shell.env, &prompt_info);

	while (1)
	{
		rl_value = readline(prompt_info.prompt);
		if (rl_value == NULL)
			break ;
		add_history(rl_value);
		tok = lexer(rl_value);
		free(rl_value);
		tok = add_end_tok(tok);
		shell.start = tok;
		exec(&shell);
		free_tok_list(&shell.start);
	}
	free_env_list(&shell.env);
	free_env_list(&shell.fallback_env);
	clear_history();
	return (0);
}

/*---------------------------------TEST----------------------------------------------------*/

// int	main(int argc, char **argv, char **envp)
// {
// 	t_env		*env;
// 	t_prompt	prompt_info;
// 	// char		*line = "cd | echo blal << out";
// 	// char		*line = "< out ls | cat | wc";
// 	char		*line = "/ls | grep Makefile";
// 	t_token		*tok = lexer(line);
	
// 	//t_shell		shell;
// 	// t_token		end_tok = {NULL, "end", END, NULL};

// // 	tok = add_end_tok(tok);
// 	// termine la liste chainée de tokens avec un token de type END == 9

// 	(void)argv;
// 	if (argc != 1)
// 		return (EXIT_FAILURE);
// 	env = get_env(envp); //a proteger
// 	get_info(env, &prompt_info);

// 	// // TEST EXEC
// //	init_shell(&shell, envp); // debut de init_shell (utilise get_env btw)
// //	shell.start = tok;
// 	// // printf("start:%s\n", shell.start->value);
// 	// exec(&shell); // exec.c marche que pour les cas simples tel que "ls | cat | wc"

	
// 	// test de la tokenisation

// 	t_token *tok_iter = tok;
// 	while (tok_iter)
// 	{
// 		printf("token type:%d value:%s\n", tok_iter->type, tok_iter->value);
// 		tok_iter = tok_iter->next;
// 	}
// 	free_env_list(&env);
// 	free_tok_list(&tok);
// 	// free(tok);
// 	return (0);
// }
	// to do before exit:
	// free_env_list(&env);
	// clear_history();