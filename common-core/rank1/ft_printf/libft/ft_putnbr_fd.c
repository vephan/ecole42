/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:55:24 by vephan            #+#    #+#             */
/*   Updated: 2025/10/11 18:09:38 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_parse(char *s, long val, int fd)
{
	int		i;

	i = 0;
	while (val > 0)
	{
		s[i] = val % 10 + '0';
		val = val / 10;
		i++;
	}
	while (i > 0)
	{
		write(fd, &s[i - 1], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	val;
	char	tmp;
	char	s[12];

	val = n;
	if (val == 0)
	{
		tmp = '0';
		write(fd, &tmp, 1);
	}
	else
	{
		if (val < 0)
		{
			val = -val;
			tmp = '-';
			write(fd, &tmp, 1);
		}
		ft_parse(s, val, fd);
	}
}
/*
#include <stdio.h>
int	main(void)
{
	ft_putnbr_fd(-10, 1);
	ft_putnbr_fd(0, 1);
	ft_putnbr_fd(100, 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putnbr_fd(2147483647, 1);
	return (0);
}*/
/*
void	ft_putnbr_fd(int n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	write(fd, s, ft_strlen(s));
	free(s);
}*/
