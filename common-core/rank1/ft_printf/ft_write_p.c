/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:07:17 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:56:04 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_p(va_list args)
{
	int				*ptr;
	char			*b;
	unsigned long	num;
	int				increment;

	ptr = va_arg(args, void *);
	if (ptr)
	{
		write(1, "0x", 2);
		b = "0123456789abcdef";
		num = (unsigned long) ptr;
		increment = 2 + ft_convert(num, b);
		return (increment);
	}
	else
	{
		write(1, "(nil)", 5);
		return (5);
	}
}
