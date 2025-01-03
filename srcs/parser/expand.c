/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:30:15 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/26 02:03:50 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/* ************************************************************************** */

char	*substitute_variables(char *str, t_env *env, int ret)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			result = ft_itoa(ret);
			i += 2;
		}
		else if (str[i] == '$' && str[i + 1])
		{
			result = handle_variable_substitution(result, str, &i, env);
		}
		else
		{
			result = handle_regular_char(result, str[i]);
			i++;
		}
	}
	return (result);
}
/* ************************************************************************** */

char	*handle_variable_substitution(char *result, char *str, int *i,
								t_env *env)
{
	char	*var_name;
	char	*var_value;
	char	*new_result;
	int		start;

	(*i)++;
	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	var_name = ft_substr(str, start, *i - start);
	if (!var_name)
		return (result);
	var_value = get_value_by_name(env, var_name);
	free(var_name);
	if (var_value)
	{
		new_result = ft_strjoin(result, var_value);
		free(result);
		result = new_result;
	}
	return (result);
}

/* ************************************************************************** */

char	*handle_regular_char(char *result, char c)
{
	char	char_as_str[2];

	char_as_str[0] = c;
	char_as_str[1] = '\0';
	result = ft_strjoin_free(result, char_as_str, 1);
	return (result);
}

/* ************************************************************************** */

void	final_process(t_token *tokens, t_env *envp, t_shell *shell)
{
	t_token	*current;
	char	*processed_value;

	current = tokens;
	while (current)
	{
		if (current->type != HEREDOC)
		{
			processed_value = handle_in_quotes(current->value, envp, shell);
			free(current->value);
			current->value = processed_value;
		}
		current = current->next;
	}
}

/* ************************************************************************** */
