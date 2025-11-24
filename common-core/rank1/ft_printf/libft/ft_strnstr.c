/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:50:58 by vephan            #+#    #+#             */
/*   Updated: 2025/10/09 09:50:58 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	min;
	unsigned int	i;
	char			*ptr_to_firstchar;

	if ((little[0] == '\0') || (little == NULL))
		return ((char *) big);
	min = (unsigned int) len;
	if (min >= ft_strlen(little))
		min = ft_strlen(little);
	if (len > 1000)
		len = 1000;
	i = 0;
	while (i < len)
	{
		ptr_to_firstchar = ft_strchr(&big[i], little[0]);
		if (ptr_to_firstchar == NULL)
			return (NULL);
		if (((int)(ptr_to_firstchar - big) + ft_strlen(little) > len))
			return (NULL);
		if (ft_strncmp(ptr_to_firstchar, little, min) == 0)
			return (ptr_to_firstchar);
		i = i + (int)(ptr_to_firstchar - big) + 1;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	int	n = -1;
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	printf("output strnstr is %s\n", strnstr(haystack, needle, n));
	printf("output ft_strnstr is %s\n", ft_strnstr(haystack, needle, n));
	return (0);
}*/
