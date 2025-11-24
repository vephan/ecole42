/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:42:10 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:55:31 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* reproduce printf in C
printf("display %c %s %p", arg1, arg2, arg3);
1- retrieve the nb or arguments
2- parse format for %, 
read the following char (cspdiuxX%)
acc to char, exec the correct write
3- iterate until end of string
input: 
format - the string to parse
variable nb of args
output - a string of characters
*/

int	ft_processformat(char c, va_list args)
{
	char	percent;

	percent = '%';
	if (c == 'c')
		return (ft_write_c(args), 1);
	else if ((c == 'd') || (c == 'i'))
		return (ft_write_i(args));
	else if (c == 's')
		return (ft_write_s(args));
	else if (c == 'u')
		return (ft_write_u(args));
	else if (c == 'p')
		return (ft_write_p(args));
	else if ((c == 'x') || (c == 'X'))
		return (ft_write_hex(args, c));
	else
		return (write(1, &percent, 1), 1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		cnt;

	cnt = 0;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			cnt = cnt + ft_processformat(format[++i], args);
		else
		{
			write(1, &format[i], 1);
			cnt++;
		}
		i++;
	}
	va_end(args);
	return (cnt);
}

/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
//	char	*s = "LOVE";
	int		res;
	int		res2;

//res = ft_printf("multiple %c, %c, %c\n", 'A', 'B', 'C');
//res2 = printf("multiple %c, %c, %c\n", 'A', 'B', 'C');
//if (res != res2)
////printf("error res %d res2 %d\n", res, res2);
//	res = printf(" %X\n", LONG_MIN);
//	res2 = ft_printf(" %X\n", LONG_MIN);
//res = printf(" %X \n", 9223372036854775807LL);
//res2 = ft_printf(" %X \n", 9223372036854775807LL);

//res = printf(" NULL %s NULL \n", NULL);
//res2 = ft_printf(" NULL %s NULL \n", NULL);

//res = printf(" %p %p \n", 0, 0);
//res2 = ft_printf(" %p %p \n", 0, 0);
	
	res = printf(" %x ", 9223372036854775807LL);
	res2 = ft_printf(" %x ", 9223372036854775807LL);
	
	if (res != res2)
		printf("error res %d res2 %d\n", res, res2);
	return (0);
}*/