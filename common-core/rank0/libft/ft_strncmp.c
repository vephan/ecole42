/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:48:35 by vephan            #+#    #+#             */
/*   Updated: 2025/10/06 11:48:35 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*compares two strings which lengths are greater than val*/
int	ft_cmp(const char *s1, const char *s2, size_t val)
{
	unsigned int	i;
	unsigned char	r1;
	unsigned char	r2;

	i = 0;
	while (i < (unsigned int) val)
	{
		r1 = (unsigned char)(s1[i]);
		r2 = (unsigned char)(s2[i]);
		if (r1 != r2)
			return (r1 - r2);
		i++;
	}
	return (0);
}

/* compares at most n char */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	min;
	unsigned char	*ptr;
	int				sign;
	int				ret;

	min = ft_strlen(s1);
	ptr = (unsigned char *) s2;
	sign = -1;
	if (ft_strlen(s1) > ft_strlen(s2))
	{
		min = ft_strlen(s2);
		ptr = (unsigned char *) s1;
		sign = 1;
	}
	if (min >= (unsigned int) n)
	{
		return (ft_cmp(s1, s2, n));
	}
	ret = ft_cmp(s1, s2, min);
	if (ret != 0)
		return (ret);
	else
		return (sign * ptr[min]);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = "1234"; //"\x12\xff\x65\x12\xbd\xde\xad";// '\0'; //"helloABCD";
	char *s2 = "1235"; //"\x12\x02";//'\0'; //"helloABCD";
	size_t n = -1;
	int r1;
	int r2;
		
	//test 1 two diff strings, n > size -OK
	//test 2 two diff strings with the same start, n < size - OK
	//test 3 two equal strings, n <>= size - OK
	//test 4 one string is NULL
	//test 5 the two strings are NULL
	r1 = strncmp(s1, s2, n);
	r2 = ft_strncmp(s1, s2, n);
	if (strncmp(s1, s2, n) != ft_strncmp(s1, s2, n))
		printf("error!!! r1 %d r2 %d \n", r1, r2);
	else
		printf("test has passed\n");
	return (0);
}*/