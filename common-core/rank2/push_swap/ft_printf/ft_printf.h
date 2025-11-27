/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:51:06 by vephan            #+#    #+#             */
/*   Updated: 2025/10/18 08:52:32 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_write_c(va_list args);
int		ft_write_i(va_list args);
int		ft_write_s(va_list args);
int		ft_write_u(va_list args);
int		ft_write_p(va_list args);
int		ft_write_hex(va_list args, char c);
int		ft_convert(unsigned long num, char *b);

#endif