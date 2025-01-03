/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:54:32 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 12:32:39 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	g_lobal_exit_code;

void	cleanup_shell(t_shell *shell)
{
	free_env_list(&shell->env);
	free_env_list(&shell->fallback_env);
	clear_history();
	if (shell->hiddn_oldpwd)
		free(shell->hiddn_oldpwd);
	if (shell->hiddn_pwd)
		free(shell->hiddn_pwd);
	close_fd(shell->in);
	close_fd(shell->out);
}

char	*get_user_input(t_prompt *prompt_info, t_env *env)
{
	get_info(env, prompt_info);
	signal(SIGINT, ft_handle_sigint);
	return (readline(prompt_info->prompt));
}

void	process_input(char *rl_value, t_shell *shell)
{
	t_token	*tok;

	tok = NULL;
	if (*rl_value == '\0')
	{
		free(rl_value);
		return ;
	}
	if (g_lobal_exit_code == 2 || g_lobal_exit_code == 3)
		shell->ret = g_lobal_exit_code + 128;
	add_history(rl_value);
	tok = lexer(rl_value, &shell->ret);
	free(rl_value);
	final_process(tok, shell->env, shell);
	if (tok)
	{
		tok = add_end_tok(tok);
		shell->start = tok;
		exec(shell);
		free_tok_list(&shell->start);
	}
}

int	main_loop(t_shell *shell)
{
	t_prompt	prompt_info;
	char		*rl_value;

	rl_value = NULL;
	while (1)
	{
		rl_value = get_user_input(&prompt_info, shell->env);
		if (rl_value == NULL)
			break ;
		process_input(rl_value, shell);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argv;
	if (argc != 1)
		return (EXIT_FAILURE);
	signal_handler();
	init_shell(&shell, envp);
	main_loop(&shell);
	cleanup_shell(&shell);
	return (0);
}
