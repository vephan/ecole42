/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 18:21:47 by vephan            #+#    #+#             */
/*   Updated: 2025/10/07 18:39:27 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr != NULL)
		ft_strlcpy(ptr, s, ft_strlen(s) + 1);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
//	int	size = 3;
	char *s1 = "lol";//(char *) malloc(sizeof(char) * (size + 1));
	char *s2 ; // = (char *) malloc(sizeof(char) (size + 1));
	char *s3;

	printf("strlen %ld\n", ft_strlen(s1));
	//memset(s1, 'A', size);
	s2 = strdup(s1); 
	printf("strdup is %s\n", s2);
	s3 = ft_strdup(s1);
	printf("ft_strdup is %s\n", s3);
	if (strncmp(s2, s3, size))
		printf("error\n");
	else
		printf("success\n");	

	free(s2);
	free(s3);
	return (0);
}*/
