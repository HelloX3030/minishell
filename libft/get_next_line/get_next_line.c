/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 09:22:12 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/07 15:25:48 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"

char	*get_buffer(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];

	return (buffer[fd]);
}

char	*handle_found_nl(char *buffer, char *next_nl, char *nl)
{
	const ptrdiff_t	found_len = next_nl - buffer + 1;
	const size_t	nl_len = ft_strlen(nl);
	char			*new_nl;

	new_nl = malloc(nl_len + found_len + 1);
	if (!new_nl)
		return (failure_cleanup(nl), NULL);
	ft_memmove(new_nl, nl, nl_len);
	ft_memmove(new_nl + nl_len, buffer, found_len);
	new_nl[nl_len + found_len] = 0;
	ft_memmove(buffer, next_nl + 1, ft_strlen(next_nl + 1) + 1);
	failure_cleanup(nl);
	return (new_nl);
}

bool	handle_start_buffer(char *buffer, char **nl, size_t *nl_r_len)
{
	char	*next_nl;

	if (!*buffer)
		return (0);
	next_nl = get_next_nl(buffer);
	if (next_nl)
		return (*nl = handle_found_nl(buffer, next_nl, *nl), 1);
	else
	{
		*nl_r_len = BUFFER_SIZE * 2;
		*nl = rstr(buffer, nl_r_len);
		if (!*nl)
			return (*nl = NULL, 1);
		else
			return (0);
	}
}

bool	read_buffer(int fd, char *buffer, char **nl, size_t *nl_r_len)
{
	char	*new_str;
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (*buffer = 0, failure_cleanup(*nl), *nl = NULL, 1);
	else if (bytes_read == 0)
	{
		if (!*nl)
			return (*buffer = 0, 1);
		*nl_r_len = 0;
		new_str = rstr(*nl, nl_r_len);
		if (!new_str)
			return (failure_cleanup(*nl), *nl = NULL, 1);
		failure_cleanup(*nl);
		*nl = new_str;
		return (*buffer = 0, 1);
	}
	buffer[bytes_read] = 0;
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*next_nl;
	char	*nl;
	size_t	nl_r_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_buffer(fd);
	nl = NULL;
	nl_r_len = 0;
	if (handle_start_buffer(buffer, &nl, &nl_r_len))
		return (nl);
	while (1)
	{
		if (read_buffer(fd, buffer, &nl, &nl_r_len))
			return (nl);
		next_nl = get_next_nl(buffer);
		if (next_nl)
			return (handle_found_nl(buffer, next_nl, nl));
		if (buffer_join(&nl, buffer, &nl_r_len))
			return (NULL);
	}
}
