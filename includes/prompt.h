/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:51:53 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/18 11:14:14 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H
# include <minishell.h>

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_prompt
{
	char	id[42];
	char	hostname[42];
	char	pwd[420];
	char	prompt[509];
}	t_prompt;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

void	get_id(t_env *env, t_prompt *info);
void	get_location(t_env *env, t_prompt *info);
void	get_pwd(t_prompt *info);
void	concat_prompt(t_prompt *info);
void	get_info(t_env *env, t_prompt *info);

#endif