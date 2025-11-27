/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:54:58 by vephan            #+#    #+#             */
/*   Updated: 2025/11/27 18:04:08 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Reverse rotate*/
int	*ft_rrotate(int *ptr, int size)
{
	int	i;
	int	tmp;

	if (size <= 1)
		return (ptr);
	i = size - 1;
	tmp = ptr[size -1];
	while (i > 0)
	{
		ptr[i] = ptr[i - 1];
		i--;
	}
	ptr[0] = tmp;
	return (ptr);
}

struct s_mem	ft_rra(struct s_mem state)
{
	state.stack_a.ptr = ft_rrotate(state.stack_a.ptr, state.stack_a.size);
	return(state);
}

struct s_mem	ft_rrb(struct s_mem state)
{
	state.stack_b.ptr = ft_rrotate(state.stack_b.ptr, state.stack_b.size);
	return(state);
}

struct s_mem	ft_rrr(struct s_mem state)
{
	(state.stack_a).ptr = ft_rrotate((state.stack_a).ptr, (state.stack_a).size);
	(state.stack_b).ptr = ft_rrotate((state.stack_b).ptr, (state.stack_b).size);
	return (state);
}