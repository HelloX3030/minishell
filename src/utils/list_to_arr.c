/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:31:15 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/01 15:35:11 by lkubler          ###   ########.fr       */
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

char	**list_to_arr(t_list *args)
{
	char	**arr;
	t_list	*current;
	int		size;
	int		i;

	size = ft_lstsize(args);
	if (size == 0)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	current = args;
	i = 0;
	while (current)
	{
		arr[i] = ft_strdup((char *)current->content);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		current = current->next;
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
