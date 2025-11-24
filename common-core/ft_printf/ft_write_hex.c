/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:27:26 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:54:34 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex(va_list args, char c)
{
	long	num;
	int		increment;
	char	*b;

	num = va_arg(args, int);
	if (num > 4294967295)
		num = 4294967295;
	if (num < (-4294967296))
		num = -4294967296;
	if (num < 0)
		num = 4294967296 + num;
	if (c == 'x')
		b = "0123456789abcdef";
	else
		b = "0123456789ABCDEF";
	increment = ft_convert(num, b);
	return (increment);
}
