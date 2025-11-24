/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:02:34 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:57:05 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
	{
		s = "(null)";
		write(1, s, 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}
