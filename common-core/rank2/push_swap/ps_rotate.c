/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:53:59 by vephan            #+#    #+#             */
/*   Updated: 2025/11/27 17:18:54 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rotate*/
int	*ft_rotate(int *ptr, int size)
{
	int	i;
	int	tmp;

	if (size <= 1 || !ptr)
		return (ptr);
	tmp = ptr[0];
	i = 0;
	while (i < (size - 1))
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
	ptr[size - 1] = tmp;
	return (ptr);
}

struct s_mem	ft_ra(struct s_mem state)
{
	state.stack_a.ptr = ft_rotate(state.stack_a.ptr, state.stack_a.size);
	return(state);
}

struct s_mem	ft_rb(struct s_mem state)
{
	state.stack_b.ptr = ft_rotate(state.stack_b.ptr, state.stack_b.size);
	return (state);
}

struct s_mem	ft_rr(struct s_mem state)
{
	(state.stack_a).ptr = ft_rotate((state.stack_a).ptr, (state.stack_a).size);
	(state.stack_b).ptr = ft_rotate((state.stack_b).ptr, (state.stack_b).size);
	return (state);
}

