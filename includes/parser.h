/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/25 17:37:23 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

char	**ft_strtok(char *string, char *sep);
char	*handle_quotes(char *str, t_env *envp, int ret);
char	*substitute_variables(char *str, t_env*env, int ret);
char	*handle_variable_substitution(char *result, char *str, int *i,
			t_env *env);
char	*handle_regular_char(char *result, char c);
void	final_process(t_token *tokens, t_env *envp, int ret);

#endif