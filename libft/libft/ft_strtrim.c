/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:23:00 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:46:47 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	char_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (true);
		set++;
	}
	return (false);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (char_in_set(s1[i], set))
		++i;
	return (i);
}

static int	get_end(const char *s1, const char *set, int start)
{
	int	i;

	i = ft_strlen(s1);
	while (i > start && char_in_set(s1[i - 1], set))
		--i;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const int	start = get_start(s1, set);
	const int	end = get_end(s1, set, start);
	char		*new_str;
	int			i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	new_str = malloc(end - start + 1);
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < end - start)
		new_str[i] = s1[i + start];
	new_str[i] = 0;
	return (new_str);
}

// int	main(void)
// {
// 	const char	*s1 = "ABABAABBXXAAAABAAA";
// 	const char	*set = "AB";
// 	char		*new_str;

// 	new_str = ft_strtrim(s1, set);
// 	printf("%s, %s: %s\n", s1, set, new_str);
// 	free(new_str);
// }
