/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:56:05 by vephan            #+#    #+#             */
/*   Updated: 2025/10/13 20:35:27 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*delete the content, free the pointer to content
free the node node*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}

/*
int	main(void)
{
	char *s1 = "lorem";
	char *s2 = "ipsum";
	char *s3 = "set";
	char *s4 = "hello";
	t_list **list;

	t_list *elem1;
	t_list *elem2;
	t_list *elem3;
	t_list *elem4;
	
	elem1 = ft_lstnew(s1);
	elem2 = ft_lstnew(s2);
	elem3 = ft_lstnew(s3);
	elem4 = ft_lstnew(s4);
	
	ft_lstadd_back(list, elem1);
	ft_lstadd_back(list, elem2);
	ft_lstadd_back(list, elem3);
	ft_lstadd_back(list, elem4);
	
	ft_lstdelone()
}*/