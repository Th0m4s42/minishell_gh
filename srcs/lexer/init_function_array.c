/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:21:37 by thbasse           #+#    #+#             */
/*   Updated: 2024/11/06 14:16:29 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init_functionarray(ft_array (*funct_array)[8])
{
	*(funct_array)[0] = check_in;
	*(funct_array)[1] = check_heredoc;
	*(funct_array)[2] = check_append;
	*(funct_array)[3] = check_trunc;
	*(funct_array)[4] = check_pipe;
	*(funct_array)[5] = check_cmd_path;
	*(funct_array)[6] = check_cmd;
	*(funct_array)[7] = check_arg;
}
