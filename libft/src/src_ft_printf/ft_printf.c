/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:36:20 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/11 08:27:42 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_format(char specifier, va_list *args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(*args, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(*args, char *));
	else if (specifier == 'p')
		count += ft_printptr(va_arg(*args, unsigned long long));
	else if (specifier == 'd')
		count += ft_printnbr(va_arg(*args, int));
	else if (specifier == 'i')
		count += ft_printnbr(va_arg(*args, int));
	else if (specifier == 'u')
		count += ft_printunbr(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		count += ft_printhex(va_arg(*args, unsigned int), specifier);
	else if (specifier == 'X')
		count += ft_printhex(va_arg(*args, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		curr;
	va_list	args;

	va_start(args, format);
	curr = 0;
	count = 0;
	while (format[curr])
	{
		if (format[curr] == '%' && format[curr + 1])
		{
			count += print_format(format[curr + 1], &args);
			curr++;
		}
		else if (format[curr] == '%')
			return (-1);
		else
			count += write(1, &format[curr], 1);
		curr++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int r1;
// 	int r2;
// 	r1 = printf("Hey salut!\n");
// 	r2 = ft_printf("Hey salut!\n");

// 	printf("%d\n", r1);
// 	printf("%d\n", r2);
// 	return (42);
// }