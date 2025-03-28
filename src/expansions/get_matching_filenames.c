/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matching_filenames.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:06:52 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/28 17:29:52 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	match_pattern(const char *pattern, const char *filename,
				char quotes);

static int	handle_star(const char *pattern, const char *filename, char quotes)
{
	while (*pattern == '*')
		pattern++;
	if (*pattern == '\0')
		return (1);
	while (*filename != '\0')
	{
		if (match_pattern(pattern + 1, filename, quotes))
			return (1);
		filename++;
	}
	return (0);
}

static int	match_pattern(const char *pattern, const char *filename,
		char quotes)
{
	while (*pattern && *filename)
	{
		if (*pattern == '*' && quotes == 0)
			return (handle_star(pattern, filename, quotes));
		else if (*pattern == '\"' && quotes == 0)
			quotes = '\"';
		else if (*pattern == '\"' && quotes == '\"')
			quotes = 0;
		else if (*pattern == '\'' && quotes == 0)
			quotes = '\'';
		else if (*pattern == '\'' && quotes == '\'')
			quotes = 0;
		else if (*pattern != *filename)
			return (0);
		else
			filename++;
		pattern++;
	}
	return (*pattern == *filename);
}

static int	add_filename(t_list *filenames, const char *pattern,
		const char *filename)
{
	char	*tmp;
	t_list	*new;
	t_list	*last;

	if (!match_pattern(pattern, filename, 0))
		return (EXIT_SUCCESS);
	last = ft_lstlast(filenames);
	if (!last)
		return (EXIT_FAILURE);
	tmp = ft_strdup(filename);
	if (!tmp)
		return (EXIT_FAILURE);
	last->content = tmp;
	new = ft_lstnew(NULL);
	if (!new)
		return (free(tmp), EXIT_FAILURE);
	ft_lstadd_back(&filenames, new);
	return (EXIT_SUCCESS);
}

t_list	*get_matching_filenames(const char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	t_list			*filenames;

	filenames = ft_lstnew(NULL);
	if (!filenames)
		return (NULL);
	dir = opendir(".");
	if (!dir)
		return (ft_lstclear(&filenames, free), NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (add_filename(filenames, pattern, entry->d_name) == EXIT_FAILURE)
			return (ft_lstclear(&filenames, free), closedir(dir), NULL);
		entry = readdir(dir);
	}
	closedir(dir);
	return (filenames);
}
