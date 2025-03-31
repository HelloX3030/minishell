/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:45:46 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/31 16:46:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_list	*add_files(t_list *lst, t_list *filenames)
{
	t_list	*next;
	t_list	*last;

	next = lst->next;
	free(lst->content);
	lst->content = filenames->content;
	lst->next = filenames->next;
	free(filenames);
	last = ft_lstlast(lst);
	if (!last->content)
	{
		if (next)
		{
			last->content = next->content;
			last->next = next->next;
			return (free(next), last);
		}
		else
		{
			next = ft_lstprevious(lst, last);
			return (free(last), next->next = NULL, NULL);
		}
	}
	else
		return (last->next = next, next);
}

int	expand_wildcards(t_list *lst)
{
	t_list	*filenames;
	t_list	*lst_start;

	lst_start = lst;
	while (lst)
	{
		filenames = get_matching_filenames(lst->content);
		if (!filenames)
			return (EXIT_FAILURE);
		if (ft_lstsize(filenames) <= 1)
		{
			ft_lstclear(&filenames, free);
			lst = lst->next;
		}
		else
			lst = add_files(lst, filenames);
	}
	return (EXIT_SUCCESS);
}
