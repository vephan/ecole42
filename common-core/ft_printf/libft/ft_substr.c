/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:09:45 by vephan            #+#    #+#             */
/*   Updated: 2025/10/08 17:10:10 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates memory (using malloc(3)) and returns a
substring from the string ’s’.
The substring starts at index ’start’ and has a
maximum length of ’len*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = (char *) malloc(sizeof(char) * (1));
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/*
#include <string.h>

int	main(void)
{
	char	*s = "";//"lorem ipsum dolor sit amet";//NULL;//"hello12345world";

	//test 1 - s is empty., start 0, len 0, start 1 len 0
	, start 0 len 2
	//test 2 - s "string", start 0, len 0, start 1 len 0, 
	start 0 len 2 (start and len < strlen)
	//test 3 - s "string", start 0, len 0, start 1 len 0,
	 start 0 len 2 (start + len > strlen)

	printf("%s\n", ft_substr(s, 2, 0)); //4294967295

	//printf("should return %s\n", substr(s, start, len));
	return (0);
}*/