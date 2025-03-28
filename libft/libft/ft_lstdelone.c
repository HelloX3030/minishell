/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:10:40 by hello_x           #+#    #+#             */
/*   Updated: 2025/03/28 16:23:31 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstdellast(t_list **lst, void (*del)(void *))
{
	t_list	*cur;

	if (!*lst)
		return ;
	if (!(*lst)->next)
	{
		ft_lstdelone(*lst, del);
		*lst = NULL;
		return ;
	}
	cur = *lst;
	while (cur->next->next)
		cur = cur->next;
	ft_lstdelone(cur->next, del);
	cur->next = NULL;
}
