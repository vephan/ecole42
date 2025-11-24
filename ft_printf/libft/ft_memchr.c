/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:34:14 by vephan            #+#    #+#             */
/*   Updated: 2025/10/06 11:34:14 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ptr;
	unsigned char	car;

	i = 0;
	ptr = (unsigned char *)s;
	car = (unsigned char) c;
	while (i < (int) n)
	{
		if (*ptr == car)
			return (ptr);
		i++;
		ptr++;
	}
	return (0);
}
/*
int main(void)
{
	size_t n = 10;
	int c = '\0';
	int *r1;
	int *r2;
	char s1[0x1ff] = "";//"hello\0world"; //"helloABCD";

	// test 1 string is valid, c is found (c is null, c is not null)
	// test 2 string is valid, c is not found (c is null, c is not null)
	// test 3 string is null
	r1 = memchr(s1, c, n);
	r2 = ft_memchr(s1, c, n);
	if (r1 != r2)
		printf("error!!\n");
	else
		printf("test has passed\n");
	return (0);
}*/