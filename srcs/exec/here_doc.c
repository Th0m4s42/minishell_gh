/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:21:20 by noam              #+#    #+#             */
/*   Updated: 2024/12/22 02:10:27 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../../libft/includes/get_next_line.h"


void	write_to_doc_file(char *file_content, int fd)
{
	write(fd, file_content, (ft_strlen(file_content)));
}

/* ************************************************************************** */

char	*create_doc_file(char *file_content, int *nb)
{
	char	*name;
	int		fd;

	name = ft_strjoin_free(".here_doc_LfFDdSUeiGYvevCciTtyciTyicTCXirxexYXQMo_", ft_itoa(*nb), 2);
	(*nb)++;
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	write_to_doc_file(file_content, fd);
	close (fd);
	return (name);
}

char	*replace_dolla_sign(char *str, t_env *env)
{
	char	*new_str;
	char	*env_name;
	int		i;
	int		j;
	char	*var_name;

	i = 0;
	j = 0;
	new_str = NULL;
	env_name = NULL;
	while (str[j])
	{
		if (str[i])
		{
			i = until_dolla_sign(str, i);
			new_str = ft_strjoin_free(new_str, ft_substr(str, j, i - j), 3);
			j = until_space(str, i);
			var_name = ft_substr(str, i + 1, j - i - 1);
			env_name = get_value_by_name(env, var_name);
			new_str = ft_strjoin_free(new_str, env_name, 1);
			i++;
			env_name = NULL;
		}
	}
	return (new_str);
}

char	*stdin_to_str(char *limiter, t_env *env, int expand)
{
	char	*line;
	char	*tru_limit;
	char	newline[2];
	char	*tmp_str;

	line = NULL;
	newline[0] = '\n';
	newline[1] = '\0';
	if (!limiter)
		tru_limit = newline;
	else
		tru_limit = limiter;
	write(2, "> ", 2);
	tmp_str = get_next_line(0);
	while (tmp_str && ft_strncmp(tmp_str, tru_limit, ft_strlen(tru_limit))
		&& glob.exit_code == 0)
	{
		if (has_dolla_sign(tmp_str) && expand)
			tmp_str = replace_dolla_sign(tmp_str, env);
		line = ft_strjoin_free(line, tmp_str, 3);
		write(2, "> ", 2);
		tmp_str = get_next_line(0);
	}
	if (tmp_str)
		free(tmp_str);
	return (line);
}

/* ************************************************************************** */

t_token	*handle_here_docs(t_token *token, t_env *env, int *doc_nb)
{
	char		*doc_name;
	char		*captured_str;
	t_token		*tmp;

	tmp = token;
	captured_str = NULL;
	while (tmp && tmp->type != END && glob.exit_code == 0)
	{
		if (tmp->type == HERE_DOC)
		{
			if (tmp->value && eradicate_quotes(tmp->value))
				captured_str = stdin_to_str(tmp->value, env, 0);
			else
				captured_str = stdin_to_str(tmp->value, env, 1);
			doc_name = create_doc_file(captured_str, doc_nb);
			free (tmp->value);
			if (!doc_name)
				tmp->value = NULL;
			tmp->value = doc_name;
		}
		tmp = tmp->next;
	}
	return (token);
}

/* ************************************************************************** */
/*
in handle_here_docs we change the << tokens by capturing stdin until limiter
save what we capture in stdin and change token->value to captured_str;

*/