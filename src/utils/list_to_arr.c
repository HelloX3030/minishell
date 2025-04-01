/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:31:15 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/01 15:31:48 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	fd_close(int fd)
{
	if (fd > 0)
		close (fd);
}

char	*path_join(const char *s1, const char *s2)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(s1, "/");
	path = ft_strjoin(tmp, s2);
	return (path);
}

char **list_to_arr(t_list *args)
{
	char	**arr;
	int		size;
	int		i;

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

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
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
