/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:31:15 by lkubler           #+#    #+#             */
/*   Updated: 2025/02/25 08:54:58 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	fd_close(int fd)
{
	if (fd > 0)
		close (fd);
}

//void	close_fds(t_command *cmd)
//{
//	fd_close(cmd->infile);
//	fd_close(cmd->outfile);
//	fd_close(cmd->inpipe);
//	fd_close(cmd->outpipe);
//}

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
