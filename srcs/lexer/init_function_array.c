/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:21:37 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/28 16:07:27 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_functionarray(bool (**ft_array)(char *, t_token *))
{
	ft_array[0] = check_cmd_path;
	ft_array[1] = check_cmd;
	ft_array[2] = check_arg;
	ft_array[3] = check_pipe;
	ft_array[4] = check_in;
	ft_array[5] = check_heredoc;
	ft_array[6] = check_append;
	ft_array[7] = check_trunc;
}
