/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:25:04 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:46:46 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include "libft.h"

int		print_format(char specifier, va_list *args);
int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(const char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_printunbr(unsigned int n);
int		ft_printhex(unsigned int nb, char specifier);

#endif