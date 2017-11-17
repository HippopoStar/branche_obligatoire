/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:48:17 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/17 03:15:41 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new_list;
	t_list	*new_link_current;
	t_list	*new_link_next;

	current = lst;
	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_link_current = new_list;
	while (current != NULL)
	{
		new_link_current = f(current);
		if (!(new_link_next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new_link_current->next = new_link_next;
		new_link_current = new_link_next;
		current = current->next;
	}
	new_link_current->next = NULL;
	return (new_list);
}
