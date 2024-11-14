/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:21:20 by noam              #+#    #+#             */
/*   Updated: 2024/11/14 16:01:45 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include "../../libft/includes/libft.h"
#include "../../libft/includes/get_next_line.h"


// void	write_to_doc_file(const char *delimiter, int ret);
// {
// 	char	*line

// 	line get_next_line(ret);
// 	while (line && ft_strncmp(line, delimiter, ft_strlen(delimiter)))
// 		write(ret, &line, ft_strlen(line))
// }

// /* ************************************************************************** */

// char	*create_doc_file(char *delimiter, int nb)
// {
// 	char	*name;
// 	int		ret;
// 	int		id;

// 	id = ft_itoa(nb);
// 	name = ft_strjoin("here_doc_nb", id);
// 	free(id);
// 	ret = open(name, O_WRONLY | O_CREAT | 0664);
// 	write_to_doc_file(delimiter, ret);
	
// }

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
			printf("new_str: %s\n", new_str);
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

// char	*stdin_to_str(const char *delimiter, t_env *env)
// {
// 	char	*line;
// 	char	*tru_delimit;
// 	char	newline[2];
// 	char	*tmp_str;

// 	line = NULL;
// 	newline[0] = '\n';
// 	newline[1] = '\0';
// 	if (!delimiter)
// 		tru_delimit = newline;
// 	else
// 		tru_delimit = delimiter;
// 	write(2, "heredoc> ", 9);
// 	tmp_str = get_next_line(0);
// 	while (tmp_str)
// 	{
// 		if (!ft_strncmp(tmp_str, tru_delimit, ft_strlen(tru_delimit)))
// 		{
// 			free(tmp_str);
// 			break;
// 		}
// 		line = ft_strjoin(line, tmp_str);
// 		free(tmp_str);
// 		write(2, "heredoc> ", 9);
// 		tmp_str = get_next_line(0);
// 	}
// 	return (line);
// }

/* ************************************************************************** */

void	handle_here_docs(t_token *token, t_env *env)
{
	// char	*doc_file;
	int		nb;
	char *captured_str;

	nb = 0;
	captured_str = NULL;
	// doc_file = NULL;
	while (token && token->type != END)
	{
		if (token->type == HERE_DOC)
		{
			captured_str = stdin_to_str(token->value, env);
			// doc_file = create_doc_file(token->value, int nb);
			free (token->value);
			// if (!doc_file)
				token->value == NULL;
			// token->value = doc_file;
		}
	}
}

/* ************************************************************************** */
/*
in handle_here_docs we change the << tokens by capturing stdin until delimiter
save what we capture in stdin and change token->value to captured_str;

*/