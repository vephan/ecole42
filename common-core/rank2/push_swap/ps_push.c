/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:52:37 by vephan            #+#    #+#             */
/*   Updated: 2025/11/27 18:04:08 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_intcpy(int *dest, int *src, int size)
{
	int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
		{
			dest[i] = src[i];
			i++;
		}
		return (dest);
	}
}

struct s_mem	ft_pa(struct s_mem state)
{
	int	*dest;
	int	*src;
	int	*new_d;
	int	*new_s;

	if ((state.stack_b).size <= 0 || !(state.stack_b).ptr)
		return (state);
	src = state.stack_b.ptr;
	dest = (state.stack_a).ptr;
	new_d = (int *) malloc(sizeof(int) * ((state.stack_a).size + 1));
	if (!new_d)
		return ((state.stack_a).ptr = NULL, state);
	if (dest && (state.stack_a).size)
		ft_intcpy((new_d + 1), dest, (state.stack_a).size);
	new_d[0] = src[0];
	(state.stack_a).size++;
	new_s = (int *) malloc(sizeof(int) * ((state.stack_b).size - 1));
	if (!new_s || (state.stack_b).size == 1)
		return (state.stack_a.ptr = new_d, state.stack_b.ptr = NULL, state.stack_b.size = 0,
			free(dest), free(src), state);
	ft_intcpy((new_s), (src + 1), (state.stack_b).size - 1);
	(state.stack_b).size--;
	return ((state.stack_a).ptr = new_d, (state.stack_b).ptr = new_s,
			 free(dest), free(src), state);
}

struct s_mem	ft_pb(struct s_mem state)
{
	int	*dest;
	int	*src;
	int	*new_d;
	int	*new_s;

	src = (state.stack_a).ptr;
	if ((state.stack_a).size <= 0 || !src)
		return (state);
	dest = (state.stack_b).ptr;
	new_d = (int *) malloc(sizeof(int) * ((state.stack_b).size + 1));
	if (!new_d)
		return ((state.stack_b).ptr = NULL, state);
	if (dest && (state.stack_b).size)
		ft_intcpy((new_d + 1), dest, (state.stack_b).size);
	new_d[0] = src[0];
	(state.stack_b).size++;
	new_s = (int *) malloc(sizeof(int) * ((state.stack_a).size - 1));
	if (!new_s || (state.stack_a).size == 1)
		return (state.stack_b.ptr = new_d, state.stack_a.ptr = NULL, state.stack_a.size = 0,
			free(dest), free(src), state);
	ft_intcpy((new_s), (src + 1), (state.stack_a).size - 1);
	(state.stack_a).size--;
	return ((state.stack_b).ptr = new_d, (state.stack_a).ptr = new_s,
		 free(dest), free(src), state);
}
