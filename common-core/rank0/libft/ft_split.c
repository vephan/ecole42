/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:46:34 by vephan            #+#    #+#             */
/*   Updated: 2025/10/10 17:33:13 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* allocate ptr, cpy and store*/
char	*ft_allocptr(char *src, int len)
{
	char	*s;

	s = (char *) malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, src, len);
	s[len] = '\0';
	return (s);
}

int	ft_cntstr(char *ptr, char c)
{
	int		cnt;
	char	*str;
	int		len;

	cnt = 0;
	if (ptr && *ptr != '\0')
	{
		str = ptr;
		while ((ft_strlen(str) > 0) && (ft_strnpchr(str, c) != NULL))
		{
			len = (int)(ft_strnpchr(str, c) - str);
			if (len >= 1)
				cnt++;
			str = ft_strnpchr(str, c) + 1;
		}
		cnt++;
	}
	return (cnt);
}

void	ft_splitstr(char **arr, char *ptr, int cnt, char c)
{
	int		j;
	int		len;
	char	*str;

	j = 0;
	str = ptr;
	while (j < cnt)
	{
		while ((*str != '\0') && (*str == c))
			str++;
		if (j < (cnt - 1))
			len = (int)(ft_strnpchr(str, c) - str);
		else
			len = ft_strlen(str);
		arr[j] = ft_allocptr(str, len);
		str = ft_strnpchr(str, c) + 1;
		j++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*ptr;
	int		cnt;

	ptr = ft_strtrim(s, &c);
	cnt = ft_cntstr(ptr, c);
	arr = (void *) malloc(sizeof(ptr) * (cnt + 1));
	if (!arr)
		return (NULL);
	ft_splitstr(arr, ptr, cnt, c);
	if (ptr)
		free(ptr);
	arr[cnt] = NULL;
	return (arr);
}
