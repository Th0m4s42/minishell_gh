/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:37:05 by thbasse           #+#    #+#             */
/*   Updated: 2024/12/21 13:24:01 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////
typedef struct s_glob
{
int 	is_child;
int 	exit_code;
} t_glob;


extern t_glob glob;
// extern int is_child;
// extern int glob->global_exit_code;

// ////////////////////////////////////////////////////////////////////////////////
// //								FONCTIONS									  //
// ////////////////////////////////////////////////////////////////////////////////

void    ft_handle_sigint(int sig);
void    signal_handler(void);


#endif