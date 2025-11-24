/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:12:11 by vephan            #+#    #+#             */
/*   Updated: 2025/10/02 10:12:11 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				i;
	int				len;
	unsigned char	*str;

	i = 0;
	len = (int) n;
	str = (unsigned char *) s;
	while (i < len)
		str[i++] = '\0';
}
