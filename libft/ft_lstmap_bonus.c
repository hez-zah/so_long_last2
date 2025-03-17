/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sellyani <sellyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:06:21 by sellyani          #+#    #+#             */
/*   Updated: 2025/02/13 19:42:08 by sellyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*old;

	if (!head || !f)
		return (NULL);
	new = NULL;
	while (head)
	{
		old = ft_lstnew (f(head->content));
		if (!old)
		{
			ft_lstclear(&old, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new, old);
		head = head->next;
	}
	return (new);
}
