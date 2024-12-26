/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:19:16 by noam              #+#    #+#             */
/*   Updated: 2024/12/26 02:04:25 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

int	find_first_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (i);
		i++;
	}
	return (i);
}

int	find_next_quote(char *str)
{
	int		i;
	char	quote;

	quote = str[0];
	if (quote == '\0')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] == quote)
			return (i + 1);
		i++;
	}
	return (i);
}

char	*process_segment(char *str, int *i, t_shell *shell, char *result)
{
	char	*temp;
	int		start;
	int		end;
	t_env	*envp;

	envp = shell->env;
	start = find_first_quote(&str[*i]);
	temp = ft_substr(str, *i, start);
	result = ft_strjoin_free(result,
			handle_quotes(temp, start - *i, envp, shell->ret), 3);
	free(temp);
	*i += start;
	end = find_next_quote(&str[*i]);
	if (end == 0)
		return (result);
	result = ft_strjoin_free(result,
			handle_quotes(&str[*i], end, envp, shell->ret), 3);
	*i += end - 1;
	(*i)++;
	return (result);
}

/* ************************************************************************** */

char	*handle_in_quotes(char *str, t_env *envp, t_shell *shell)
{
	char	*result;
	char	*temp;
	int		len;
	int		i;

	len = ft_strlen(str);
	result = NULL;
	i = 0;
	while (i < len)
	{
		result = process_segment(str, &i, shell, result);
		if (i >= len)
			break ;
	}
	temp = ft_substr(str, i, len - i);
	result = ft_strjoin_free(result,
			handle_quotes(temp, len, envp, shell->ret), 3);
	free(temp);
	return (result);
}

/* ************************************************************************** */

char	*handle_quotes(char *str, int len, t_env *envp, int ret)
{
	char	*result;
	char	*temp;

	result = NULL;
	if (str[0] == '\'' && str[len - 1] == '\'')
	{
		result = ft_substr(str, 1, len - 2);
	}
	else if (str[0] == '\"' && str[len - 1] == '\"')
	{
		temp = ft_substr(str, 1, len - 2);
		result = substitute_variables(temp, envp, ret);
		free(temp);
	}
	else
		result = substitute_variables(str, envp, ret);
	return (result);
}
/* ************************************************************************** */
