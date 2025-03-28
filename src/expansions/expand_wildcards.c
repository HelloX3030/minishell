/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcards.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:45:46 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/28 14:26:25 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	match_pattern(const char *pattern, const char *filename)
{
	if (*pattern == '\0' && *filename == '\0')
		return (1);
	if (*pattern == '*')
	{
		while (*(pattern + 1) == '*')
			pattern++;
		if (*(pattern + 1) == '\0')
			return (1);
		while (*filename != '\0')
		{
			if (match_pattern(pattern + 1, filename))
				return (1);
			filename++;
		}
		return (match_pattern(pattern + 1, filename));
	}
	if (*pattern == *filename || (*pattern == '?' && *filename != '\0'))
		return (match_pattern(pattern + 1, filename + 1));
	return (0);
}

static int	add_filename(t_list *filenames, const char *pattern,
		const char *filename)
{
	char	*tmp;
	t_list	*new;
	t_list	*last;

	if (!match_pattern(pattern, filename))
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

static t_list	*get_matching_filenames(const char *pattern)
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

int	expand_wildcards(char **str)
{
	t_list	*filenames;
	t_list	*tmp;

	(void)str;
	filenames = get_matching_filenames("test*");
	printf("filenames: %p\n", filenames);
	if (!filenames)
		return (EXIT_FAILURE);
	tmp = filenames;
	while (tmp && tmp->content)
	{
		printf("filename: %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
