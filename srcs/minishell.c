/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:13 by thbasse           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/24 04:19:03 by thbasse          ###   ########.fr       */
=======
/*   Updated: 2024/11/27 17:49:46 by noam             ###   ########.fr       */
>>>>>>> cb3963da1cad42065218d1a8b2fdd7368a53423a
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_token	*add_end_tok(t_token *toks, t_token end_tok)
{
	t_token	*tmp;

	tmp = toks;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = &end_tok;
	end_tok.prev = tmp;
	return (toks);
}

int	main(int argc, char **argv, char **envp)
{
	//char		*rl_value;
	t_env		*env;
	t_prompt	prompt_info;
<<<<<<< HEAD
	char		*line = "d/u fun \'pour toi\'du fun\"pour |moi\" | cmd1 | cmd2 <<input>> output |cmd";
=======
	// char		*line = "d/u fun \'pour toi\'du fun\"pour |moi\" | cmd1 | cmd2 <input>> output |cmd";
	char		*line = "| ls | cat | wc > output";
>>>>>>> cb3963da1cad42065218d1a8b2fdd7368a53423a
	t_token		*tok = lexer(line);
	
	t_shell		shell;
	t_token		end_tok = {NULL, NULL, END, NULL};

	tok = add_end_tok(tok, end_tok);
	// termine la liste chainée de tokens avec un token de type END == 9

	(void)argv;
	//rl_value = NULL;
	if (argc != 1)
		return (EXIT_FAILURE);
	env = get_env(envp); //a proteger
	get_info(env, &prompt_info);

<<<<<<< HEAD
	//------------test de la tokenisation------------------------------------
=======
	// TEST EXEC
	init_shell(&shell, envp); // debut de init_shell (utilise get_env btw)
	tok = tok->next;	// alors j'arrive pas a juste mettre "cmd 1, cmd 2" du coup je fais ca
	tok->prev = NULL;	// pour que ca marche "/cmdpath ls | cat" -> "ls | cat"
	shell.start = tok;
	// printf("start:%s\n", shell.start->value);
	exec(&shell); // exec.c marche que pour les cas simples tel que "ls | cat | wc"

	
	// test de la tokenisation
>>>>>>> cb3963da1cad42065218d1a8b2fdd7368a53423a

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
	return (0);
}
	// to do before exit:
	// free_env_list(&env);
	// clear_history();