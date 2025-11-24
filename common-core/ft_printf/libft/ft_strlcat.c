/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:13:26 by vephan            #+#    #+#             */
/*   Updated: 2025/10/06 11:14:07 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	int		val;

	i = ft_strlen(dst);
	j = 0;
	val = i + ft_strlen(src);
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	while ((i < (dstsize - 1)) && (src[j] != 0))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (val);
}
/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = ft_strlen(dst);
	ret = j + ft_strlen(src);
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && j < (dstsize - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ret);
}
*/
/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	max;
	char	*s1;
	char	*s2;

	s1 = (char *) src;
	s2 = (char *) dst;
	srclen = ft_strlen(s1);
	i = ft_strlen(dst);
	max = ft_strlen(dst);
	if ((int) max >= (int) dstsize)
		return (dstsize + srclen);
		// max = dstsize;
	//if (src == NULL)
	//	return (i);
	s2 = s2 + i;
	while (((int) i < (int)(dstsize - 1)) && (*s1 != 0))
	{
		*s2++ = *s1++;
		i++;
	}
	*s2 = '\0';
	return (max + ft_strlen(src));
}*/
/* 
int main(void)
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
	char s1[0xF00] = "there is no stars in the sky";
	char s2[0xF00] = "there is no stars in the sky";
	//size_t max = -1;
	size_t r1 = strlcat(s1, str, -1);
	size_t r2 = ft_strlcat(s2, str, -1);

//char *str = "the cake is a lie !\0I'm hidden lol\r\n";
//char s1[0xF00] = "there is no stars in the sky";
//char s2[0xF00] = "there is no stars in the sky";
//size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") 
+ strlen("there is no stars in the sky");

//char *str = "the cake is a lie !\0I'm hidden lol\r\n";
//char s1[0xF00] = "there is no stars in the sky";
//char s2[0xF00] = "there is no stars in the sky";
//size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
//size_t r1 = strlcat(s1, str, max);
//size_t r2 = ft_strlcat(s2, str, max);

//printf("srclen: %lu\n", strlen(str));
//printf("max: %zu\n", max);
//printf("buff1 len: %lu\n", strlen(buff1));

//printf("r1: %zu\n", r1);
//printf("r2: %zu\n", r2);
//printf("buff1: %s\n", buff1);
//printf("buff2: %s\n", buff2);
//
//if (r1 != r2)
//	exit(0);
	
//	char *str = "thx to ntoniolo for this test !";
//	char s1[4] = "";
//	char s2[4] = "";
//	size_t r1 = strlcat(s1, str, 4);
//	size_t r2 = ft_strlcat(s2, str, 4);
	printf("srclen: %lu\n", strlen(str));
	printf("r1: %zu\n", r1);
	printf("r2: %zu\n", r2);
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	if (r1 != r2)
		exit(0);
	exit(1);
}*/
/*
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		ret_size;
	size_t	max;
	char	*tmp;

	if (size <= (size_t)(ft_strlen(dst) + 1))
		return (ft_strlen(src) + ft_strlen(dst));
	else
	{
		ret_size = 0;
		tmp = dst + ft_strlen(dst);
		max = size;
		if (max > ft_strlen(src))
			max = ft_strlen(src);
		while (ret_size < (int) max)
		{
			tmp[ret_size] = src[ret_size];
			ret_size++;
		}
		tmp[ret_size] = '\0';
	}
	return (ret_size);
}
*/