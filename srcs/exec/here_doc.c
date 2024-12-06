/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:21:20 by noam              #+#    #+#             */
/*   Updated: 2024/11/27 15:10:30 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include "../../libft/includes/libft.h"
#include "../../libft/includes/get_next_line.h"


void	write_to_doc_file(char *file_content, int fd)
{
	// char	*line

	// line get_next_line(ret);
	// while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter)))
	write(fd, file_content, (ft_strlen(file_content)));
	
}

/* ************************************************************************** */

char	*create_doc_file(int nb, char *file_content)
{
	char	*name;
	int		fd;
	// int		id;

	// id = ft_itoa(nb);
	name = ft_strjoin_free("here_doc_LfFDdSUeiGYvevCciTtyciTyicTCXirxexYXQMo_", ft_itoa(nb), 2);
	// free(id);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,  0664);
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
			// printf("new_str: %s\n", new_str);
			j = until_space(str, i);
			env_name = ft_substr(str, i, j - i);
			env_name = get_value_by_name(env, env_name);
			new_str = ft_strjoin_free(new_str, env_name, 1);
			i++;
			env_name = NULL;
		}
	}
	return (new_str);
}

char	*stdin_to_str(char *delimiter, t_env *env)
{
	char	*line;
	char	*tru_delimit;
	char	newline[2];
	char	*tmp_str;

	line = NULL;
	newline[0] = '\n';
	newline[1] = '\0';
	if (!delimiter)
		tru_delimit = newline;
	else
		tru_delimit = delimiter;
	// fprintf(stderr, "the deli is %s\n" , delimiter);
	write(2, "> ", 2);
	tmp_str = get_next_line(0);
	while (tmp_str && ft_strncmp(tmp_str, tru_delimit, ft_strlen(tru_delimit)))
	{
		if (has_dolla_sign(tmp_str))
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

t_token	*handle_here_docs(t_token *token, t_env *env)
{
	char		*doc_name;
	char	 *captured_str;
	int					id;
	t_token				*tmp;

	tmp = token;
	id = 0;
	captured_str = NULL;
	// doc_file = NULL;
	while (tmp && tmp->type != END)
	{
		if (tmp->type == HERE_DOC)
		{
			captured_str = stdin_to_str(tmp->value, env);
			doc_name = create_doc_file(id, captured_str);
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
in handle_here_docs we change the << tokens by capturing stdin until delimiter
save what we capture in stdin and change token->value to captured_str;

*/