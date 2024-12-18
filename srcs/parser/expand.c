/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:30:15 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/18 13:15:44 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <minishell.h>

char	*handle_quotes(char *str, char **envp)
{
	char	*result;
	char	*temp;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (str[0] == '\'' && str[len - 1] == '\'')
	{
		result = ft_substr(str, 1, len - 2);
	}
	else if (str[0] == '"' && str[len - 1] == '"')
	{
		temp = ft_substr(str, 1, len - 2);
		result = substitute_variables(temp, envp);
		free(temp);
	}
	return (result);
}

char	*substitute_variables(char *str, char **env)
{
	char	*result;
	char	*var_name;
	char	*var_value;
	int		start;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			start = i;
			while (ft_isprint(str[i]))
				i++;
			var_name = ft_substr(str, start, i - start);
			var_value = get_value_by_name(env, var_name);
			result = ft_strjoin(result, var_value);
			free(var_name);
			if (var_value)
				result = ft_strjoin(result, var_value);
			else
				result = ft_strjoin(result, "");
		}
		else
		{
			result = ft_strlcat(result, str[i], 1);
			i++;
		}
	}
	return (result);
}
