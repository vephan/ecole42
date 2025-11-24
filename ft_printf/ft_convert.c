/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:53:58 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:54:16 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(unsigned long num, char *b)
{
	int	counter;

	counter = 0;
	if (num >= 16)
	{
		counter = ft_convert(num / 16, b);
		write(1, &b[num % 16], 1);
		counter++;
	}
	else
	{
		write(1, &b[num], 1);
		counter++;
	}
	return (counter);
}
