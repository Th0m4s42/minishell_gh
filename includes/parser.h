/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/26 02:25:21 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

char	**ft_strtok(char *string, char *sep);
char	*handle_quotes(char *str, int len, t_env *envp, int ret);
char	*substitute_variables(char *str, t_env*env, int ret);
char	*handle_variable_substitution(char *result, char *str, int *i,
			t_env *env);
char	*handle_regular_char(char *result, char c);

#endif