/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:21:20 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 02:10:37 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include "../../libft/includes/get_next_line.h"

/* ************************************************************************** */

char	*create_doc_file(char *file_content, int *nb)
{
	char	*name;
	int		fd;

	(*nb)++;
	name = ft_strjoin_free(".here_doc_sOme_nAme_ThATwOn'T_cOnfLict_.tmp",
			ft_itoa(*nb), 2);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	write(fd, file_content, (ft_strlen(file_content)));
	free(file_content);
	close (fd);
	return (name);
}

/* ************************************************************************** */
char	*proccess_var(char *newstr, char *str, int i[], t_shell *shell)
{
	char	*var_name;
	char	*value;

	if (str[i[0] + 1] == '?')
	{
		newstr = ft_strjoin_free(newstr, ft_substr(str, i[1], i[0] - i[1]), 3);
		var_name = ft_itoa(shell->ret);
		newstr = ft_strjoin_free(newstr, var_name, 3);
		i[0] += 2;
		i[1] = i[0];
	}
	else
	{
		newstr = ft_strjoin_free(newstr, ft_substr(str, i[1], i[0] - i[1]), 3);
		i[1] = until_space(str, i[0]);
		var_name = ft_substr(str, i[0] + 1, i[1] - i[0] - 1);
		value = get_value_by_name(shell->env, var_name);
		free(var_name);
		var_name = NULL;
		newstr = ft_strjoin_free(newstr, value, 1);
		i[0]++;
	}
	return (newstr);
}

/* ************************************************************************** */

char	*replace_dolla_sign(char *str, t_shell *shell)
{
	char	*new_str;
	int		i;
	int		j;
	int		sum[2];

	i = 0;
	j = 0;
	new_str = NULL;
	sum[0] = i;
	sum[1] = j;
	while (str[sum[1]])
	{
		sum[0] = until_dolla_sign(str, sum[0]);
		if (str[sum[0]] == '$')
			new_str = proccess_var(new_str, str, sum, shell);
		else
		{
			new_str = ft_strjoin_free(new_str,
					ft_substr(str, sum[1], sum[0] - sum[1]), 3);
			break ;
		}
	}
	free(str);
	return (new_str);
}

/* ************************************************************************** */

char	*stdin_to_str(char *limiter, t_shell *shell, int expand)
{
	char	*line;
	char	*tmp_str;

	line = NULL;
	tmp_str = readline(">> ");
	while (tmp_str && ft_strncmp(tmp_str, limiter, ft_strlen(limiter) + 1))
	{
		tmp_str = ft_strjoin_free(tmp_str, "\n", 1);
		if (has_dolla_sign(tmp_str) && expand)
			tmp_str = replace_dolla_sign(tmp_str, shell);
		if (g_lobal_exit_code == 130)
			break ;
		line = ft_strjoin_free(line, tmp_str, 3);
		tmp_str = readline("> ");
	}
	if (tmp_str)
		free(tmp_str);
	return (line);
}

/* ************************************************************************** */

t_token	*handle_here_docs(t_token *token, t_shell *shell, int *doc_nb)
{
	char		*doc_name;
	char		*captured_str;
	t_token		*tmp;

	tmp = token;
	captured_str = NULL;
	while (tmp && tmp->type != END)
	{
		if (tmp->type == HERE_DOC)
		{
			if (tmp->value && eradicate_quotes(tmp->value))
				captured_str = stdin_to_str(tmp->value, shell, 0);
			else
				captured_str = stdin_to_str(tmp->value, shell, 1);
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