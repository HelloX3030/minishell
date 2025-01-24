/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:47:45 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/28 10:40:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const int	len1 = ft_strlen(s1);
	const int	len2 = ft_strlen(s2);
	char		*new_str;
	int			i;
	int			j;

	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	while (++i < len1)
		new_str[i] = s1[i];
	j = -1;
	while (++j < len2)
		new_str[i + j] = s2[j];
	new_str[i + j] = 0;
	return (new_str);
}

// int	main(void)
// {
// 	const char	*s1 = "ABC";
// 	const char	*s2 = "ZZZZ";
// 	char		*new_str;

// 	new_str = ft_strjoin(s1, s2);
// 	printf("%s\n", new_str);
// 	free(new_str);
// }
