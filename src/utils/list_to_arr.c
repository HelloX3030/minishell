/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:31:15 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/08 16:40:41 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	get_size(t_list *args)
{
	int	size;

	size = 0;
	while (args)
	{
		if (args->content && ft_strcmp(args->content, ""))
			size++;
		args = args->next;
	}
	return (size);
}

static char	**to_arr(t_list *args, int size)
{
	char	**arr;
	int		i;

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
			i++;
		}
		args = args->next;
	}
	arr[size] = NULL;
	return (arr);
}

char	**list_to_arr(t_list *args)
{
	int		size;
	char	**arr;

	size = get_size(args);
	if (size > 0)
		return (to_arr(args, size));
	else
	{
		arr = (char **)malloc(sizeof(char *) * 2);
		if (!arr)
			return (NULL);
		arr[0] = ft_strdup("");
		if (!arr[0])
			return (free(arr), NULL);
		arr[1] = NULL;
		return (arr);
	}
}

int	is_directory(const char *path)
{
	DIR	*dir_check;
	int	result;

	dir_check = opendir(path);
	result = dir_check != NULL;
	if (dir_check)
		closedir(dir_check);
	return (result);
}
