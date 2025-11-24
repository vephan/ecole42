/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:02:31 by vephan            #+#    #+#             */
/*   Updated: 2025/10/02 12:21:07 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int				i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (dest == NULL && src == NULL)
		return (NULL);
	else
	{
		s1 = (unsigned char *) src;
		s2 = (unsigned char *) dest;
		i = 0;
		while (i < (int) n)
		{
			s2[i] = s1[i];
			i++;
		}
		return (dest);
	}
}
