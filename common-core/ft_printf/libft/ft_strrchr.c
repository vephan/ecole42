/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:49:47 by vephan            #+#    #+#             */
/*   Updated: 2025/10/06 11:52:33 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		tmp;
	int		isfound;

	if (((ft_isprint((char) c) == 0) && ((char) c != '\0')))
		return (NULL);
	else
	{
		i = 0;
		isfound = 0;
		while (s[i])
		{
			if (s[i] == (char) c)
			{
				tmp = i;
				isfound = 1;
			}
			i++;
		}
		if ((char) c == '\0')
			return ((char *)(s + ft_strlen(s)));
		if (isfound)
			return ((char *)(s + tmp));
		return (NULL);
	}
}
/*
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		tmp;
	int		isfound;
	char	car;

	car = (char) c;
	if (((ft_isprint(car) == 0) && (car != '\0')))
		return (NULL);
	else
	{
		i = 0;
		isfound = 0;
		while (s[i])
		{
			if (s[i] == car)
			{
				tmp = i;
				isfound = 1;
			}
			i++;
		}
		if (car == '\0')
			return ((char *)(s + ft_strlen(s)));
		if (isfound)
			return ((char *)(s + tmp));
		return (NULL);
	}
}*/

/*
int main(void)
{
	char *buff1; // = (char *) malloc(sizeof(char) * (size));
	char *buff2; // = (char *) malloc(sizeof(char) * (size));

	// test 1: string valid, char can be found	- buff1 is an address -OK 
	// test 1bis: string is valid, char can be found at different places -OK 
	// test 2: string valid, char can not be found - buff1 is null - OK
	// test 3: string valid with null terminator in the middle, char is present
	// but after the null - buff1 is null - OK
	// test 6: string valid, c null - OK
	// test 6 bis: string valid, c null in different places - OK
	// test 4: string is null, c is not - crash OK
	// test 5: string null, c null -crash OK
    // test 7: string valid with null before end of string, c is null - OK
    
    char *s = '\0';//"hello\0world\0111wo";
    char c = 'h';// '9'  
    buff1 = strrchr(s, c);
    buff2 = ft_strrchr(s, c);

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