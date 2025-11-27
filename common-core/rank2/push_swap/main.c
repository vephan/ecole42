/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:20:21 by vephan            #+#    #+#             */
/*   Updated: 2025/11/27 18:04:07 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check if this is an integer; 1 - yes*/
int	ft_isnum(char	*s)
{
	int	i;

	if (!(s[0] == '-' || (s[0] >= '0' && s[0] <= '9')))
		return (0);
	i = 1;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *nptr)
{
	int				sign;
	unsigned int	i;
	long			val;

	while (*nptr && (((*nptr >= 9) && (*nptr <= 13)) || (*nptr == ' ')))
		nptr++;
	i = 0;
	sign = 1;
	while (*nptr && ((*nptr == '-') || (*nptr == '+')))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
		i++;
	}
	if (i >= 2)
		return (0);
	i = 0;
	val = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		val = val * 10 + (int) nptr[i] - 48;
		i++;
	}
	return (sign * val);
}

int	*parse_arg(int *list_a, char **argv, int size)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (i < size)
	{
		s = argv[i];
		if (!ft_isnum(s) || ft_atol(s) > MAX_INT || ft_atol(s) < MIN_INT)
			return (free(list_a), ft_printf("Error\n"), NULL);
		else
		{
			j = 0;
			while (j < i)
			{
				if (ft_atoi(s) == list_a[j])
					return (free(list_a), ft_printf("Error\n"), NULL);
				j++;
			}
			list_a[i] = ft_atoi(s);
		}
		i++;
	}
	return (list_a);
}

void	display_smem(struct s_mem state)
{
	int	i;
	int	size;

	size = state.stack_a.size;
	ft_printf("size a: %d\n", size);
	i = 0;
	while (i < size)
		ft_printf("%d\n", state.stack_a.ptr[i++]);
	size = state.stack_b.size;
	ft_printf("size b: %d\n", size);
	i = 0;
	while (i < size)
		ft_printf("%d\n", state.stack_b.ptr[i++]);
}

/*test the basic operations and display them*/
int	main(int argc, char **argv)
{
	int				size;
	int				*list_a;
	struct s_mem	state;

	if (argc <= 1)
		return (0);
	else
	{
		size = argc - 1;
		list_a = (int *) malloc(sizeof(int) * size);
		if (!list_a)
		{
			ft_printf("malloc issue");
			return (0);
		}
		list_a = parse_arg(list_a, &argv[1], size);
		if (!list_a)
			return (0);
		state.stack_a.ptr = list_a;
		state.stack_a.size = size;
		state.stack_b.ptr = NULL;
		state.stack_b.size = 0;
		display_smem(state);
		state = ft_sa(state);
		ft_printf("after sa\n");
		display_smem(state);
		state = ft_pb(state);
		ft_printf("after pb\n");
		display_smem(state);
		state = ft_pb(state);
		ft_printf("after pb\n");
		display_smem(state);
		state = ft_pb(state);
		ft_printf("after pb\n");
		display_smem(state);
		state = ft_sb(state);
		ft_printf("after sb\n");
		display_smem(state);
		state = ft_ss(state);
		ft_printf("after ss\n");
		display_smem(state);
		state = ft_rr(state);
		ft_printf("after rr\n");
		display_smem(state);
		state = ft_ra(state);
		ft_printf("after ra\n");
		display_smem(state);
		state = ft_rb(state);
		ft_printf("after rb\n");
		display_smem(state);
		state = ft_rrr(state);
		ft_printf("after rrr\n");
		display_smem(state);
		state = ft_rrb(state);
		ft_printf("after rrb\n");
		display_smem(state);
		state = ft_rra(state);
		ft_printf("after rra\n");
		display_smem(state);
	}
	return (0);
}