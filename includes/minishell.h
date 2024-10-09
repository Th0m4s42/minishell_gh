/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:13:03 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/09 17:49:28 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <curses.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/includes/libft.h"
# include <env.h>
# include <lexer.h>
# include <parser.h>
# include "signal.h"


////////////////////////////////////////////////////////////////////////////////
//								ENUM										  //
////////////////////////////////////////////////////////////////////////////////

typedef enum s_redir_type
{
	IN,			// 0
	HERE_DOC,	// 1
	APPEND,		// 2
	TRUNC		// 3
}	t_redir_type;

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	struct s_line	*next;
}					t_cmd;

typedef struct s_token
{
	char			*string;
	int				token;
}					t_token;

typedef struct s_redir
{
	char			*name;
	t_redir_type	type;
	struct s_redir	*next;
}					t_redir;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

#endif