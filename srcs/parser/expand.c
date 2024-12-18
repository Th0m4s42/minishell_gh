/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:30:15 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/18 16:39:52 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>

char	*handle_quotes(char *str, t_env *envp)
{
	char	*result;
	char	*temp;
	int		len;

	result = ft_strdup("");
	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
	{
		result = ft_substr(str, 1, len - 2);
	}
	else if (str[0] == '\"' && str[len - 1] == '\"')
	{
		temp = ft_substr(str, 1, len - 2);
		result = substitute_variables(temp, envp);
		free(temp);
	}
	return (result);
}

char	*substitute_variables(char *str, t_env *env)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
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

char	*handle_variable_substitution(char *result, char *str, int *i, t_env*env)
{
	char	*var_name;
	char	*var_value;
	int		start;

	(*i)++;
	start = *i;
	while (ft_isprint(str[*i]) && str[*i] != ' ' && str[*i] != '$')
		(*i)++;
	var_name = ft_substr(str, start, *i - start);
	var_value = get_value_by_name(env, var_name);
	free(var_name);
	if (var_value)
		result = ft_strjoin(result, var_value);
	else
		result = ft_strjoin(result, "");
	return (result);
}

char	*handle_regular_char(char *result, char c)
{
	char	*char_as_str;

	char_as_str = ft_substr(&c, 0, 1);
	result = ft_strjoin(result, char_as_str);
	free(char_as_str);
	return (result);
}

void	final_process(t_token *tokens, t_env *envp)
{
	t_token	*current;
	char	*processed_value;

	current = tokens;
	while (current)
	{
		if (current->value)
		{
			processed_value = handle_quotes(current->value, envp);
			free(current->value);
			current->value = processed_value;
		}
		current = current->next;
	}
}
