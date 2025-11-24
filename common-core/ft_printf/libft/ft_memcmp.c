/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:14:27 by vephan            #+#    #+#             */
/*   Updated: 2025/10/06 11:14:37 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while ((i < (int) n) && (str1[i] == str2[i]))
		i++;
	if (i >= (int) n)
		return (0);
	return (str1[i] - str2[i]);
}
/*
int	main(void)
{
	char	s1[0x1FF] = "abcdefghij";
	char	s2[0x1FF] = "abcdefgxyz";
	size_t n = 7;
	int	r1;
	int	r2;	
	
	//test 1 non-null: n < strlen, s > strlen, n = strlen
	//test 2 s1 is null
	//test 3 s2 is null
	//test 4 s1 & s2 are null

	r1 = memcmp(s1, s2, n);
	r2 = ft_memcmp(s1, s2, n);
	if (r1 != r2)
		printf("r1 %d, r2 %d, s1 %s, s2 %s\n", r1, r2, s1, s2);
	else
		printf("success\n");
	return (0);
}*/