/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:17:32 by vephan            #+#    #+#             */
/*   Updated: 2025/10/13 21:03:30 by vephan           ###   ########.fr       */
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
			free(node->next);
			*lst = NULL;
		}
		lst = NULL;
	}
}
