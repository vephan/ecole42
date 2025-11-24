/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:25:53 by vephan            #+#    #+#             */
/*   Updated: 2025/10/06 11:28:53 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*accepts all printable char and stops at first char found*/
char	*ft_strchr(const char *s, int c)
{
	char	*ptr_to_c;
	char	car;

	car = (char) c;
	if ((ft_isprint(car) == 0) && (car != '\0'))
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
/*
char	*ft_strchr(const char *s, int c)
{
	char	*ptr_to_c;

	if (((isprint(c) == 0) && (c != '\0')) || (s == NULL))
		return (NULL);
	else
	{
		ptr_to_c = (char *) s;
		while (*ptr_to_c)
		{
			if (*ptr_to_c == c)
				return (ptr_to_c);
			ptr_to_c++;
		}
		if (c == '\0')
			return (ptr_to_c);
		return (NULL);
	}
}*/

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *buff1; // = (char *) malloc(sizeof(char) * (size));
	char *buff2; // = (char *) malloc(sizeof(char) * (size));

	// test 1: string valid, char can be found	- buff1 is an address -OK 
    // test 2: string valid, char can not be found - buff1 is null - OK
    // test 3: string valid with null terminator in the middle, char is present
    // but after the null - buff1 is null - OK
    // test 4: string is null, c is not - crash OK
    // test 5: string null, c null -crash OK
    // test 6: string valid, c null - OK
    // test 7: string valid with null before end of string, c is null - OK
    
    char *s = "helloworld111";
    char c = '1' + (char) 256;// '9'  
    buff1 = strchr(s, c);
    buff2 = ft_strchr(s, c);

    if (buff1 != buff2)
    {
        printf("error. buff1 %p buff2 %p\n", buff1, buff2);
        printf("c is %c\n", c);
        printf("searched string %s\n addr is %p\n", s, s);
    }
    else 
        printf("success\n");
    return (0);
}*/