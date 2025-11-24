/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:09:46 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:44:57 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countdigits(long num)
{
	int		cnt;
	char	tmp;

	cnt = 0;
	if (num >= 10)
	{
		cnt = ft_countdigits(num / 10);
		tmp = (char)(num % 10) + '0';
		write(1, &tmp, 1);
		cnt++;
	}
	else
	{
		tmp = (char) num + '0';
		write(1, &tmp, 1);
		cnt = 1;
	}
	return (cnt);
}

int	ft_write_u(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_countdigits(num));
}
