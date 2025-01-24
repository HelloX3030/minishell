/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:44:45 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 18:30:02 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_node(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*new_lst;
	void	*new_content;

	new_content = f(lst->content);
	new_lst = ft_lstnew(new_content);
	if (new_lst == NULL)
	{
		del(new_content);
		return (NULL);
	}
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	if (lst == NULL)
		return (NULL);
	new_lst = create_node(lst, f, del);
	if (new_lst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_element = create_node(lst, f, del);
		if (new_element == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst->next;
	}
	return (new_lst);
}
