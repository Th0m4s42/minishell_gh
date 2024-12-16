/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:30:15 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/16 11:52:58 by thbasse          ###   ########.fr       */
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
	char	*cmd_output;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			char *var_name = get_variable_name(&str[i + 1]);
			char *var_value = get_env_value(env, var_name);
			result = ft_strjoin_free(result, var_value);
			free(var_name);
			i += ft_strlen(var_name);
		}
	}
	return (result);
}
