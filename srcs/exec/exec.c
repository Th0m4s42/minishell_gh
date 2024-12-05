/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/12/06 00:12:05 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
// #include <libft.h>

/* ************************************************************************** */

char	**format_cmd(const char *cmd_str)
{
	char	**cmd_n_args;

	cmd_n_args = ft_split(cmd_str, ' ');
	return (cmd_n_args);
}

/* ************************************************************************** */

void	exec_cmd(t_shell *shell, t_token *token)
{
	char	**cmd;
	// int		i;

	cmd = format_cmd(token->value);
	// i = 0;
	if (cmd && is_built_in(cmd[0]))
		exec_built_in(cmd, shell->env);
	else if (cmd)
		exec_bin(cmd, shell->env);
	ft_free_tab(cmd);
	close(shell->pipin);
	close(shell->pipout);
	shell->pipin = -1;
	shell->pipout = -1;
	shell->charge = 0;
}


void	print_shell(t_shell *shell)
{
	fprintf(stderr, "in: %d\n", shell->in);
	fprintf(stderr, "out: %d\n", shell->out);
	fprintf(stderr, "fdin: %d\n", shell->fdin);
	fprintf(stderr, "fdout: %d\n", shell->fdout);
	fprintf(stderr, "pipin: %d\n", shell->pipin);
	fprintf(stderr, "pipout: %d\n", shell->pipout);
	fprintf(stderr, "pid: %d\n", shell->pid);
	fprintf(stderr, "charge: %d\n", shell->charge);
	fprintf(stderr, "parent: %d\n", shell->parent);
	// fprintf(stderr, "last: %d\n", shell->last);
	fprintf(stderr, "exec: %d\n", shell->exec);
}
/* ************************************************************************** */

void	redir_and_exec(t_shell *shell, t_token *token)
{
	t_token	*next;
	t_token	*prev;
	int		pipe;

	next = next_sep(token);
	prev = prev_sep(token);
	pipe = 0;
	// 	if (prev)
	// 	fprintf(stderr, "prev %s\n", prev->value);
	// fprintf(stderr, "token %s\n", token->value);
	// if (next)
	// fprintf(stderr, "next %s\n", next->value);
	// if (token->type == TRUNC)
	if (is_type(prev, TRUNC))
		redir(shell, prev, TRUNC);
	else if (is_type(prev, APPEND))
		redir(shell, token, APPEND);
	else if (is_type(prev, IN))
		input(shell, prev);
	else if (is_type(prev, HERE_DOC))
		input(shell, token);
	else if (is_type(prev, PIPE))
		pipe = pipe_n_fork(shell);
	if (next && next->type != END && pipe !=1)
		redir_and_exec(shell, next->next);
	if ((!prev || prev->type == PIPE ||token->type == CMD)
			&& pipe != 1 && shell->exec && shell->charge)
		{
		// fprintf(stderr, "\033[0;36m");

		print_shell(shell);
		// fprintf(stderr, "the token issss === %s\n", token->value);
		// fprintf(stderr, "\033[0m");

		exec_cmd(shell, token);
		}
	return ;
}

/* ************************************************************************** */



void	exec(t_shell *shell)
{
	t_token	*token;
	int		status;

	token = shell->start;
	// handle_here_docs(&token, shell->env);
	// while (shell->exec && token)
	// {
		shell->parent = 1;
		shell->charge = 1;
		redir_and_exec(shell, token);
		reset_stds(shell);
		close_reset_fd(shell);
		waitpid(shell->pid, &status, 0);
		if (shell->charge == 0 && shell->parent == 0)
			exit(0);
		// we should be catching the last child status here but idk how yet
	// }
}
