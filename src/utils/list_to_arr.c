/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:31:15 by lkubler           #+#    #+#             */
/*   Updated: 2025/03/10 15:08:45 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int get_size(t_list *args)
{
	int size;

	size = 0;
	while (args)
	{
		if (args->content && ft_strcmp(args->content, ""))
			size++;
		args = args->next;
	}
	return (size);
}

char **list_to_arr(t_list *args)
{
	char **arr;
	int size;
	int i;

	size = get_size(args);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (args)
	{
		if (args->content && ft_strcmp(args->content, ""))
		{
			arr[i] = ft_strdup(args->content);
			if (!arr[i])
				return (ft_free_strs_partial(arr, i), NULL);
		}
		args = args->next;
		i++;
	}
	arr[size] = NULL;
	return (arr);
}
