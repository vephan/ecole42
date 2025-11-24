/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:09:29 by vephan            #+#    #+#             */
/*   Updated: 2025/10/02 10:11:29 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	int				len;
	unsigned char	*str;

	i = 0;
	len = (int) n;
	str = (unsigned char *) s;
	while (i < len)
		str[i++] = c;
	return (s);
}
