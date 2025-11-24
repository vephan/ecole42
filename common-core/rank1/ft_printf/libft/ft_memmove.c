/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:25:06 by vephan            #+#    #+#             */
/*   Updated: 2025/10/02 14:25:22 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned int	i;

	s1 = (unsigned char *) src;
	s2 = (unsigned char *) dest;
	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	if (s1 >= s2)
	{
		while (i++ < (unsigned int) n)
			*s2++ = *s1++;
	}
	else
	{
		s1 = s1 + (n - 1);
		s2 = s2 + (n - 1);
		while (i++ < (unsigned int) n)
			*s2-- = *s1--;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	val = 10;
	char	dst[10] = "ABCDEFGHIJ";
	char	*src = (char *) malloc(sizeof(char) * (val + 1));

	printf("0 dest: %s\n", dst);
	src = &dst[3];
	printf("before src: %s dest: %s\n", src, dst);
//	memset(dst, 'Z', 10);
	//printf("after memset src: %s dest: %s\n", src, dst);
	ft_memmove(dst, src, val);
	printf("after src: %s dest: %s\n", src, dst);
	return (0);
	
	int size = 3;//128 * 1024 * 1024;
	char *dst = (char *)malloc(sizeof(char) * size);
	char *data = (char *)malloc(sizeof(char) * size);
 
	memset(data, 'A', size);
	memset(data, 'A', size);
	if (!dst)
		exit(0);
	ft_memmove(dst, data, size);
	exit(1);	
}*/