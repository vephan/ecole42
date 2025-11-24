/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:55:48 by vephan            #+#    #+#             */
/*   Updated: 2025/10/14 15:55:48 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*node;

	if (lst == NULL)
		return (0);
	i = 1;
	node = lst;
	while (node -> next != NULL)
	{
		node = node->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int main(void)
{
	t_list		*list[4];
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");
	int			size;

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);

	ft_lstadd_front(list, elem4);
	ft_lstadd_front(list, elem3);
	ft_lstadd_front(list, elem2);
	ft_lstadd_front(list, elem);
	 
	size = ft_lstsize(*list);
	printf("size is %d\n", size);
	return (0);
}*/