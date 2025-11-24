/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:54:49 by vephan            #+#    #+#             */
/*   Updated: 2025/10/14 15:54:59 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Function Name ft_itoa
Prototype char *ft_itoa(int n);
Files to Submit -
Parameters n: The integer to convert.
Return Value The string representing the integer.
NULL if the allocation fails.
External Function malloc
Description Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.
*/

static void	ft_convertitoa(char *s, int n, int cnt)
{
	long	val;
	int		i;
	int		end;

	end = cnt;
	val = n;
	if (n < 0)
	{
		s[0] = '-';
		val = -val;
		end++;
	}
	i = 0;
	while (i < cnt)
	{
		s[(end - 1) - i] = (val % 10) + 48;
		val = val / 10;
		i++;
	}
	s[end] = '\0';
}

static int	ft_getcnt(long val)
{
	int	cnt;

	cnt = 0;
	if (val > 0)
	{
		while (val > 0)
		{
			val = val / 10;
			cnt++;
		}
	}
	else
		cnt = 1;
	return (cnt);
}

char	*ft_itoa(int n)
{
	int		cnt;
	long	val;
	char	*s;
	int		is_sign;

	is_sign = 0;
	val = n;
	if (n < 0)
	{
		val = -val;
		is_sign = 1;
	}
	cnt = ft_getcnt(val);
	s = (char *) malloc(sizeof(char) * (cnt + 1 + is_sign * 1));
	if (!s)
		return (NULL);
	ft_convertitoa(s, n, cnt);
	return (s);
}

/*
int	main(void)
{
	char *res;

	res = ft_itoa(-10);
	printf("res %s\n", res);
	free(res);
	res = ft_itoa(0);
	printf("res %s\n", res);
	free(res);
	res = ft_itoa(100);
	printf("res %s\n", res);
	free(res);
	res = ft_itoa(-2147483648);
	printf("res %s\n", res);
	free(res);	
	res = ft_itoa(2147483647);
	printf("res %s\n", res);
	free(res);	
	return (0);
}*/