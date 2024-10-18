/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:36:50 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/18 10:40:16 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

/* list_env_manip.c */
t_env	*new_env_node(char *content, char *value);
void	add_back(t_env **first, t_env *new);
void	free_env_list(t_env **first_node);
char	*get_value_by_name(t_env *env, char *name);

/* env.c */
bool	get_env_variable_name(char *envp, char **name);
bool	get_env_variable_value(char *envp, char **value);
t_env	*get_env(char **envp);
void	iter_shlvl(t_env *env);

#endif