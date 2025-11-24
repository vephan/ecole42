/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:54:15 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:59:07 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countdigits(long num)
{
	int	cnt;

	cnt = 0;
	if (num >= 10)
	{
		cnt = ft_countdigits(num / 10);
		cnt++;
	}
	else
		cnt = 1;
	return (cnt);
}

int	ft_write_i(va_list args)
{
	int		num;
	int		cnt;
	long	val;

	cnt = 0;
	num = va_arg(args, int);
	val = (long) num;
	if (val < 0)
	{
		val = -val;
		cnt = 1;
	}
	cnt = cnt + ft_countdigits(val);
	ft_putnbr_fd(num, 1);
	return (cnt);
}
