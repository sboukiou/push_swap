/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:06:05 by sboukiou          #+#    #+#             */
/*   Updated: 2024/11/09 14:06:09 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list_head;
	void	*content_temp;
	t_list	*temp;

	new_list_head = NULL;
	temp = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (temp)
	{
		content_temp = f(temp->content);
		new_node = ft_lstnew(content_temp);
		if (!new_node)
		{
			del(content_temp);
			ft_lstclear(&new_list_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_head, new_node);
		temp = temp->next;
	}
	return (new_list_head);
}
