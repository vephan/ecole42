/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vephan <vephan@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:46:48 by vephan            #+#    #+#             */
/*   Updated: 2025/10/15 16:11:45 by vephan           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*new_content;

	if (lst && f && del)
	{
		new = NULL;
		while (lst)
		{
			new_content = f(lst->content);
			if (!new_content)
				return (ft_lstclear(&new, del), NULL);
			tmp = ft_lstnew(new_content);
			if (!tmp)
				return (del(new_content), ft_lstclear(&new, del), NULL);
			ft_lstadd_back(&new, tmp);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}

/*

void	*ft_map(void *ct)
{
	int i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}

void    ft_del(void *content)
{
	free(content);
}

int main(void)
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*new;
	char		*str = ft_strdup("lorem");
	char		*str2 = ft_strdup("ipsum");
	char		*str3 = ft_strdup("dolor");
	char		*str4 = ft_strdup("sit");
	int			i;
	
	elem = ft_lstnew(str);
	elem2 = ft_lstnew(str2);
	elem3 = ft_lstnew(str3);
	elem4 = ft_lstnew(str4);

	ft_lstadd_back(&elem, elem2);
	ft_lstadd_back(&elem, elem3);
	ft_lstadd_back(&elem, elem4);

	new = ft_lstmap(elem, &ft_map, &ft_del);
	i = 0;
	while (new->next !=NULL)
	{
		printf("new first elem: content %s next %p\n",
		 (char *) (new->content), new-> next);
		new = new -> next;
		i++;
	}
	printf("new first elem: content %s next %p\n",
	 (char *) (new->content), new-> next);
	printf("i %d", i);
	return (0);
}
*/