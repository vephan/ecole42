/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:38:14 by vephan            #+#    #+#             */
/*   Updated: 2025/10/14 10:27:34 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*tmp;

	if (lst)
	{
		node = *lst;
		if (node)
		{
			while (node->next != NULL)
			{
				del(node->content);
				tmp = node;
				node = node->next;
				free(tmp);
			}
			del(node->content);
			if (node -> next != NULL)
				free(node->next);
			*lst = NULL;
		}
		if (node)
			free(node);
		lst = NULL;
	}
}

/*
void free_str_ptr(void *str)
{
	free(str);
}

#include <stdio.h>
int main(void)
{
	t_list		*list[1];
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);

	ft_lstadd_front(list, elem4);
	ft_lstadd_front(list, elem3);
	ft_lstadd_front(list, elem2);
	ft_lstadd_front(list, elem);
	
	ft_lstclear(list, free_str_ptr);
	return (0);
}*/