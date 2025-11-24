/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:46:07 by vephan            #+#    #+#             */
/*   Updated: 2025/10/13 21:08:12 by vephan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *new;
	t_list	node;
	int		i;

	if (lst)
	{
		i = ft_lstsize(lst);
		new = (t_list *) malloc(sizeof(t_list)); 
		node = lst;
		while (node->next != NULL)
		{
			f(node->content);
		}
	}
}