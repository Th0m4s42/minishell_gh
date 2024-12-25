/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:54:05 by noam              #+#    #+#             */
/*   Updated: 2024/12/25 02:00:22 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

int	get_tab_len(t_token *cmd_tok)
{
	t_token	*tok;
	int		tab_len;

	tok = cmd_tok;
	tab_len = 0;
	if (!tok || !tok->value)
		return (0);
	while (tok && (tok->type == ARG || !tab_len))
	{
		tab_len++;
		tok = tok->next;
	}
	return (tab_len);
}

/* ************************************************************************** */

char	**format_cmd(t_token *cmd_tok)
{
	char	**format_cmd;
	t_token	*tok;
	int		tab_len;
	int		i;

	tab_len = get_tab_len(cmd_tok);
	tok = cmd_tok;
	i = 0;
	if (tab_len == 0)
		return (NULL);
	format_cmd = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!format_cmd)
		return (NULL);
	while (tok && (tok->type == ARG || i == 0))
	{
		if (tok->value)
			format_cmd[i] = ft_strdup(tok->value);
		else
			format_cmd[i] = ft_strdup("\0");
		i++;
		tok = tok->next;
	}
	format_cmd[i] = NULL;
	return (format_cmd);
}

/* ************************************************************************** */

void	exec_cmd(t_shell *shell, t_token *token)
{
	char	**cmd;

	cmd = format_cmd(token);
	if (cmd && is_built_in(cmd[0]))
		shell->ret = exec_built_in(cmd, shell->env, shell);
	else if (cmd)
		shell->ret = exec_bin(cmd, shell->env);
	ft_free_tab(cmd);
	close_fd(shell->pipin);
	close_fd(shell->pipout);
	shell->pipin = -1;
	shell->pipout = -1;
	shell->charge = 0;
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
	if (is_type(prev, TRUNC))
		redir(shell, prev, TRUNC);
	else if (is_type(prev, APPEND))
		redir(shell, prev, APPEND);
	else if (is_type(prev, IN))
		input(shell, prev);
	else if (is_type(prev, HERE_DOC))
		input(shell, prev);
	else if (is_type(token, PIPE))
		pipe = pipe_n_fork(shell);
	if (next && next->type != END && pipe != 1)
		redir_and_exec(shell, next);
	if ((!prev || prev->type == PIPE || token->type == CMD
			|| token->type == CMD_PATH) && (token->type == CMD_PATH
			|| token->type == CMD) && pipe != 1 && shell->exec && shell->charge)
		exec_cmd(shell, token);
	return ;
}


void pid_exchange(int *pipefd, int *pid) {
    if (pid == 0) { 
        // Close read end; we're writing the last child's PID
        close(pipefd[0]);
        write(pipefd[1], &pid, sizeof(pid));
        close(pipefd[1]);
    } else {
        // Close write end; we're reading the last child's PID
        close(pipefd[1]);
        read(pipefd[0], &pid, sizeof(pid));
        close(pipefd[0]);
    }
}

/* ************************************************************************** */

void	exec(t_shell *shell)
{
	t_token		*token;
	int			current_doc_nb;
	static int	doc_nb;

	token = shell->start;
	current_doc_nb = doc_nb;
	signal(SIGINT, ft_handle_sigint_doc);
	token = handle_here_docs(token, shell->env, &doc_nb);
	signal(SIGINT, ft_handle_sigint_child);
	g_lobal_exit_code = 0;
		shell->last = 1;				/////////
	shell->parent = 1;
	shell->charge = 1;
	pipe(shell->pipe_pid);
	redir_and_exec(shell, token);
	int			status = 0;			//////
	reset_stds(shell);
	close_reset_fd(shell);
	fprintf(stderr, "Before waitpid: P= %d, last= %d PID= %d\n", shell->parent, shell->last, shell->pid);
	// if (shell->parent || shell->last)
		// pid_exchange(shell->pipe_pid, &shell->pid);
	if (shell->last)
		waitpid(0, &status, 0);
		// fprintf(stderr, "\n LAST REACHED\n");
	else
	{
		waitpid(shell->pid, &status, 0);
		fprintf(stderr, "status= %d\n", status);
		if(WIFEXITED(status))
			shell->ret = (WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			shell->ret = 128 + WTERMSIG(status);
		else 
			shell->ret = status;
		fprintf(stderr, "shell_stats %d\n", shell->ret);
	}
	fprintf(stderr, "aafter waitpid: P= %d, last= %d PID= %d REURNT= %d\n", shell->parent, shell->last, shell->pid, shell->ret); 
	if (shell->charge == 0 && shell->parent == 0)
	{
			if (shell->last)
		fprintf(stderr, "\n LAST REACHED EEEEEND\n");
		exit (shell->ret);
	}
	fprintf(stderr, "\nfinally: status=%d, shell-ret=%d \n", status, shell->ret);
	del_docs(&doc_nb, current_doc_nb);
}
