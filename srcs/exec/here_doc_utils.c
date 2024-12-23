/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:25 by noam              #+#    #+#             */
/*   Updated: 2024/12/23 16:09:14 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	until_space(char *str, int i)
{
	if (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n'
		&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
		i++;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_') && str[i] != '$')
		i++;
	return (i);
}

bool	has_dolla_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	until_dolla_sign(char *str, int i)
{
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}

void	del_docs(int *doc_nb, int initial_doc_nb)
{
	char	*name;

	name = NULL;
	if (*doc_nb == 0)
		return ;
	while (*doc_nb > initial_doc_nb)
	{
		name = ft_strjoin_free(".here_doc_sOme_nAme_ThATwOn'T_cOnfLict_.tmp",
				ft_itoa(*doc_nb), 2);
		unlink(name);
		(*doc_nb)--;
		free(name);
	}
}

bool	eradicate_quotes(char *str)
{
	int		i;
	int		j;
	bool	boo;

	i = 0;
	j = 0;
	boo = false;
	if (!str)
		return (boo);
	while (str[i])
	{
		while (str[i] && (str[i] == '\'' || str[i] == '\"'))
		{
			i++;
			boo = true;
		}
		if (str[i])
		{
			str[j] = str[i];
			j++;
			i++;
		}
	}
	str[j] = '\0';
	return (boo);
}
