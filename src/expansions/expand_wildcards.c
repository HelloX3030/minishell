/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:45:46 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/28 16:30:07 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static t_list	*insert_wildcard_expansion(t_list *args, t_list *filenames)
{
	t_list	*next;
	t_list	*last;

	if (!args || !filenames)
		return (args);
	next = args->next;
	args->next = filenames;
	ft_lstdellast(&filenames, free);
	last = ft_lstlast(filenames);
	if (last)
		last->next = next;
	return (next);
}

int	expand_wildcards(t_list *args)
{
	t_list	*filenames;
	t_list	*tmp;

	while (args)
	{
		filenames = get_matching_filenames(args->content);
		if (!filenames)
			return (EXIT_FAILURE);
		if (!filenames->content)
		{
			ft_lstclear(&filenames, free);
			args = args->next;
			continue ;
		}
		free(args->content);
		args->content = filenames->content;
		tmp = filenames->next;
		free(filenames);
		filenames = tmp;
		args = insert_wildcard_expansion(args, filenames);
	}
	return (EXIT_SUCCESS);
}

// Test Code
// int	expand_wildcards(char **str)
// {
// 	t_list	*filenames;
// 	t_list	*tmp;

// 	(void)str;
// 	filenames = get_matching_filenames("\"te\"st*");
// 	printf("filenames: %p\n", filenames);
// 	if (!filenames)
// 		return (EXIT_FAILURE);
// 	tmp = filenames;
// 	while (tmp && tmp->content)
// 	{
// 		printf("filename: %s\n", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&filenames, free);
// 	return (EXIT_SUCCESS);
// }
