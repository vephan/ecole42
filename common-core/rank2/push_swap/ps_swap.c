/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:50:33 by vephan            #+#    #+#             */
/*   Updated: 2025/11/27 18:04:08 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*contains all the c routines to execute the operations*/
int	*ft_swap(int *ptr, int size)
{
	int	tmp;

	if (size <= 1)
		return (ptr);
	tmp = ptr[1];
	ptr[1] = ptr[0];
	ptr[0] = tmp;
	return (ptr);
}

struct s_mem	ft_sa(struct s_mem state)
{
	(state.stack_a).ptr = ft_swap((state.stack_a).ptr, (state.stack_a).size);
	return (state);
}

struct s_mem	ft_sb(struct s_mem state)
{
	(state.stack_b).ptr = ft_swap((state.stack_b).ptr, (state.stack_b).size);
	return (state);
}

struct s_mem	ft_ss(struct s_mem state)
{
	int	*tmp;
	int	size;

	tmp = (state.stack_a).ptr;
	size = (state.stack_a).size;
	if (size > 1)
		(state.stack_a).ptr = ft_swap(tmp, size);
	tmp = (state.stack_b).ptr;
	size = (state.stack_b).size;
	if (size > 1)
		(state.stack_b).ptr = ft_swap(tmp, size);
	return (state);
}
