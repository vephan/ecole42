/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:58:07 by vephan            #+#    #+#             */
/*   Updated: 2025/11/27 14:50:27 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

#ifndef MAX_INT
#	define MAX_INT 2147483647
#endif
#ifndef MIN_INT
#	define MIN_INT (-2147483648)
#endif

struct s_stack {
	int	*ptr;
	int	size;
};

struct s_mem {
	struct s_stack	stack_a;
	struct s_stack	stack_b;
};

int				*ft_swap(int *ptr, int size);
struct s_mem	ft_sa(struct s_mem state);
struct s_mem	ft_sb(struct s_mem state);
struct s_mem	ft_ss(struct s_mem state);
struct s_mem	ft_pa(struct s_mem state);
struct s_mem	ft_pb(struct s_mem state);
int				*ft_rotate(int *ptr, int size);
struct s_mem	ft_ra(struct s_mem state);
struct s_mem	ft_rb(struct s_mem state);
struct s_mem	ft_rr(struct s_mem state);
int				*ft_rrotate(int *ptr, int size);
struct s_mem	ft_rra(struct s_mem state);
struct s_mem	ft_rrb(struct s_mem state);
struct s_mem	ft_rrr(struct s_mem state);

#endif