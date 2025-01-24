/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:58:35 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:44:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_c_dif(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	get_str_count(const char *s, char c)
{
	int	count;
	int	dif;

	count = 0;
	while (*s != 0)
	{
		dif = get_c_dif(s, c);
		if (!dif)
			s++;
		else
		{
			count++;
			s += dif;
		}
	}
	return (count);
}

static bool	custom_copy(const char *s, int len, char **strs, int strs_i)
{
	int	i;

	strs[strs_i] = malloc(sizeof(char) * (len + 1));
	if (strs[strs_i] == NULL)
	{
		while (--strs_i >= 0)
			free(strs[strs_i]);
		free(strs);
		return (false);
	}
	i = -1;
	while (++i < len)
		strs[strs_i][i] = s[i];
	strs[strs_i][i] = 0;
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		strs_i;
	int		dif;

	strs = malloc(sizeof(char *) * (get_str_count(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	strs_i = 0;
	while (*s != 0)
	{
		dif = get_c_dif(s, c);
		if (!dif)
			s++;
		else
		{
			if (!custom_copy(s, dif, strs, strs_i++))
				return (NULL);
			s += dif;
		}
	}
	strs[strs_i] = NULL;
	return (strs);
}

// int	main(void)
// {
// 	const char	*s = "AA";
// 	char		c;
// 	char		**strs;
// 	int			i;

// 	c = 'z';
// 	strs = ft_split(s, c);
// 	if (strs == NULL)
// 		return (1);
// 	i = 0;
// 	while (strs[i] != NULL)
// 	{
// 		printf("%s\n", strs[i]);
// 		free(strs[i]);
// 		i++;
// 	}
// 	free(strs);
// 	return (0);
// }
