/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 14:59:08 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*get_var_end(char *str)
{
	if (ft_isdigit(*str))
		return (str + 1);
	while (ft_isalpha(*str) || *str == '_')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (str);
}

char	*create_terminated_str(int len)
{
	char	*result;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	return (result);
}

int	match_pattern(char *pattern, char *filename)
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

int	count_matching_files(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(".");
	if (!dir)
		return (-1);
	while ((entry = readdir(dir)))
	{
		if (match_pattern(pattern, entry->d_name))
			count++;
	}
	closedir(dir);
	return (count);
}

char	**get_matching_filenames(char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**filenames;
	int				i;
	int				file_count;

	file_count = count_matching_files(pattern);
	if (file_count <= 0)
	{
		filenames = malloc(sizeof(char *));
		if (!filenames)
			return (NULL);
		filenames[0] = NULL;
		return (filenames);
	}
	filenames = malloc((file_count + 1) * sizeof(char *));
	if (!filenames)
		return (NULL);
	dir = opendir(".");
	if (!dir)
	{
		free(filenames);
		return (NULL);
	}
	i = 0;
	while ((entry = readdir(dir)))
	{
		if (match_pattern(pattern, entry->d_name))
		{
			filenames[i] = ft_strdup(entry->d_name);
			if (!filenames[i])
			{
				while (--i >= 0)
					free(filenames[i]);
				free(filenames);
				closedir(dir);
				return (NULL);
			}
			i++;
		}
	}
	filenames[i] = NULL;
	closedir(dir);
	return (filenames);
}
