/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:40:56 by vephan            #+#    #+#             */
/*   Updated: 2025/10/08 17:06:00 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	long	size;
	char	*s;
	int		i1;
	int		i2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(sizeof(char) * size);
	if (!s)
		return (NULL);
	i1 = 0;
	i2 = 0;
	if (s1 != NULL)
	{
		ft_memcpy(s, s1, ft_strlen(s1));
		i1 = ft_strlen(s1);
	}
	if (s2 != NULL)
	{
		ft_memcpy(s + i1, s2, ft_strlen(s2));
		i2 = ft_strlen(s2);
	}
	s[i1 + i2] = '\0';
	return (s);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str1 = "abcde";
	char *str2 = "12345";
	char *s;

	s = ft_strjoin(str1, str2);
	printf("%s\n", s);
	free (s);
	return (0);
}
*/