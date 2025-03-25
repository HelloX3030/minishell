/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:48:49 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 15:06:27 by lseeger          ###   ########.fr       */
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

static char	*get_var_value(char **str_pos, t_minishell *ms,
		t_quote_type quote_type)
{
	char	*var_end;
	char	*var_name;
	char	*var_value;

	(void)quote_type;
	// expand depending on quote type
	if (**str_pos == '?')
		return ((*str_pos)++, ft_itoa(ms->status));
	var_end = get_var_end(*str_pos);
	if (var_end == *str_pos)
		return (ft_strdup("$"));
	var_name = ft_strndup(*str_pos, var_end);
	if (!var_name)
		return (NULL);
	var_value = get_env_value(ms->env, var_name);
	if (!var_value)
	{
		var_value = ft_strdup("");
		if (!var_value)
			return (free(var_name), NULL);
	}
	free(var_name);
	*str_pos = var_end;
	return (ft_strdup(var_value));
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
		return (NULL);
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
