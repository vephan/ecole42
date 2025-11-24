/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:48:27 by vephan            #+#    #+#             */
/*   Updated: 2025/10/09 13:47:43 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters s1: The string to be trimmed.
set: The string containing the set of characters
to be removed.
Return Value The trimmed string.
NULL if the allocation fails.
External Function malloc
Description Allocates memory (using malloc(3)) and returns a
copy of ’s1’ with characters from ’set’ removed
from the beginning and the end.*/

char	*ft_strnpchr(const char *s, int c)
{
	char	*ptr_to_c;
	char	car;

	car = (char) c;
	if (!(((car >= 32) && (car <= 126)) || ((car >= 9) && (car <= 13))))
		return (NULL);
	else
	{
		ptr_to_c = (char *) s;
		while (*ptr_to_c)
		{
			if (*ptr_to_c == car)
				return (ptr_to_c);
			ptr_to_c++;
		}
		if (car == '\0')
			return (ptr_to_c);
		return (NULL);
	}
}

char	*ft_alloc1byte(void)
{
	char	*s;

	s = (char *) malloc(sizeof(char) * (1));
	if (!s)
		return (NULL);
	*s = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	if (*set == '\0' || set == NULL)
		return (ft_strdup(s1));
	start = 0;
	while ((start < ft_strlen(s1)) && (ft_strnpchr(set, s1[start]) != NULL))
		start++;
	if (start == (ft_strlen(s1)))
		return (ft_alloc1byte());
	end = (ft_strlen(s1) - 1);
	while ((end > start) && (ft_strnpchr(set, s1[end]) != NULL))
		end--;
	s = (char *) malloc(sizeof(char) * ((end + 1) - start + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + start, (end + 1) - start + 1);
	return (s);
}

/*
#include <stdio.h>

int main(void)
{
	char	*big = "";//" lorem ipsum dolor sit amet";
	//char	*big1 = "   \t  \n\n \t\t  \n\n\n";
	char	*totrim = "";

	//tested valid big, totrim exists (start, middle)
	//tested valid big, totrim not found 
	//tested valid big, totrim empty
	//tested valid empty /empty
	// big empty, totrim not empty
	//big NULL or totrim NULL- null
	
	printf("ft_strtrim |%s|\n", ft_strtrim(big, totrim));
	return (0);
}*/