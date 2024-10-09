/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:13:03 by thbasse           #+#    #+#             */
/*   Updated: 2024/10/09 13:15:05 by thbasse          ###   ########.fr       */
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

# define CMD 101
# define SEP 102
# define RED 103
# define PIP 104

////////////////////////////////////////////////////////////////////////////////
//								STRUCTURES									  //
////////////////////////////////////////////////////////////////////////////////

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_line
{
	char			**env;
	char			*line;
	char			*cmd;
	char			**args;
	char			*sep;
}					t_line;

typedef struct s_token
{
	char			*string;
	int				token;
}					t_token;

////////////////////////////////////////////////////////////////////////////////
//								FONCTIONS									  //
////////////////////////////////////////////////////////////////////////////////

char	**ft_split(char const *s, char c);

#endif