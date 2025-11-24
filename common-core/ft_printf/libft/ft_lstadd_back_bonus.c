/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:19:55 by vephan            #+#    #+#             */
/*   Updated: 2025/10/13 20:27:27 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		node = *lst;
		while (node -> next != NULL)
		{
			node = node -> next;
		}
		node -> next = new;
	}
}

/*
int	main(void)
{
	char *str = "lorem";
	char *str2 = "ipsum";
	char *str3 = "dolor";
	char *str4 = "sit";
	t_list	*elem;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list *list[4];
	
	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);
	
	ft_lstadd_back(list, elem);
	ft_lstadd_back(list, elem2);
	ft_lstadd_back(list, elem3);
	ft_lstadd_back(list, elem4);
	
	return (0);
}*/
