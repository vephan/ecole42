/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:43:48 by vephan            #+#    #+#             */
/*   Updated: 2025/10/03 16:43:48 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (srclen);
	while ((src[i] != 0) && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
/*
int	main(void)
{
//char *str = "hello !";
//char buff1[0xF00];
//char buff2[0xF00];
//size_t r1;
//size_t r2;

//memset(buff1, 'A', 20);
//memset(buff2, 'A', 20);
//r1 = strlcpy(buff1, str, 2);
//r2 = ft_strlcpy(buff2, str, 2);
//printf("r1 = %zu, r2 = %zu\n", r1, r2);
//printf("buff1 = %s\n",buff1);
//printf("buff2 = %s\n",buff2);
//if (r1 == r2)
////exit(1);
//exit(0);

//char *str = "BBBB";
//char buff1[0xF00];
//char buff2[0xF00];
//size_t r1;
//size_t r2;
//
//ft_strlcpy(((void*)0), ((void*)0), 10);
////strlcpy(((void*)0), ((void*)0), 10);

//memset(buff1, 'A', 20);
//memset(buff2, 'A', 20);
//r1 = strlcpy(buff1, str, 2);
//r2 = ft_strlcpy(buff2, str, 2);
//printf("r1 = %zu, r2 = %zu\n", r1, r2);
//if (r1 == r2)
////exit(1);
//exit(0);



	//test 2: src = null - no cpy, return (0)
	//test 3: size = 1  - copy, return (0)
	//test 4: size > 1 et dst > size, cpy (size - 1), return (size - 1)
	//test 5: size > 1 et dst < size, cpy (dest_len), return (size - 1)

//char *str = "the cake is a lie !\0I'm hidden lol\r\n";
//char buff1[0xF00];
//char buff2[0xF00];
//size_t r1;
//size_t r2;

//r1 = strlcpy(buff1, str, sizeof(buff1));
//r2 = ft_strlcpy(buff2, str, sizeof(buff2));
//printf("r1 = %zu, r2 = %zu\n", r1, r2);
//if (r1 == r2)
////exit(1);
//exit(0);
}*/