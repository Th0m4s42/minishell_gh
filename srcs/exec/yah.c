#include <exec.h>
#include <libft.h>
#include <env.h>


char	**format_cmd(const char *cmd_str)
{
	char	**cmd_n_args;

	cmd_n_args = ft_split(cmd_n_args, ' ');
	return (cmd_n_args);
}

/* ************************************************************************** */

void	exec_cmd(t_shell *shell, t_token *token)
{
	char	**cmd;
	int		i;

	cmd = format_cmd(token);
	i = 0;
	if (cmd && is_built_in(cmd[0]))
		exec_built_in(cmd, shell->env);
	else if (cmd)
		exec_bin(cmd, shell->env, shell);
	ft_free_tab(cmd);
	close(shell->pipin);
	close(shell->pipout);
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
	if (is_type(prev, TRUNC))
		redir(shell, token, TRUNC);
	else if (is_type(prev, APPEND))
		redir(shell, token, APPEND);
	else if (is_type(prev, IN))
		input(shell, token);
	else if (is_type(prev, HERE_DOC))
		input(shell, token);
	else if (is_type(prev, PIPE))
		pipe_n_fork(shell, token);
	if (next && next->type != END && pipe !=1)
		redir_and_exec(shell, next);
	if ((prev->type == END || prev->type == PIPE || !prev)
		&& pipe != 1 && shell->exec)
		return ;
		// exec_cmd(shell, token);
}

/* ************************************************************************** */

void	exec(t_shell *shell)
{
	t_token	*token;

	token = shell->start;
	handle_here_docs(&token, shell->env);
	while (shell->exec && token)
	{
		shell->parent = 1;
		shell->charge = 1;
		redir_and_exec(shell, token);
	}
}

bool	is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

t_token	*ft_lstlast_(t_token *lst)
{
	t_token	*last;

	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_lstadd_back_(t_token **lst, t_token *new)
{
	t_token	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_(*lst);
	last->next = new;
	new->prev = last;
}

int		extract_token(char *str, char *sep, int *index)
{
	int		i;
	int		j;
	char	*token;

	i = *index;
	j = 0;
	token = malloc(sizeof(char) * (toklen(str, sep) + 1));
	while (str[i] && is_sep(str[i], sep))
		i++;
	while (str[i] && !is_sep(str[i], sep))
		token[j++] = str[i++];
	token[j] = '\0';
	*index = i;
	return (token);
}

t_token	*build_tokens(char *str)
{
	t_token	*start;
	t_token	*tmp;
	// t_token *prev;
	int		i;

	i = 0;
	start = NULL;
	// prev = NULL;
	while (str[i])
	{
		tmp = malloc(sizeof(t_token));
		tmp->value = extract_token(str, " \t\n", &i);
		tmp->type = ft_atoi(str + i);
		while (str[i] && !is_sep(str[i], " \t\n"))
			i++;
		tmp->next = NULL;	
		tmp->prev = NULL;
		ft_lstadd_back(&start, tmp);

	}
	return (start);
}


int main (int ac, char **argv, char **envp)
{
	t_shell	shell;
	t_token	*token;
	// t_token tmp;
	t_env	*env;

	shell.env = get_env(envp);
	shell.start = NULL;
	shell.in = STDIN;
	shell.out = STDOUT;
	shell.fdin = STDIN;
	shell.fdout = STDOUT;
	shell.pipin = -1;
	shell.pipout = -1;
	shell.pid = 0;
	shell.charge = 0;
	shell.parent = 0;
	shell.exec = 1;
	

	shell.start = build_tokens(argv[1]);


	exec(&shell);
	return (0);

}
