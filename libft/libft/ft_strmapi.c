/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:29:22 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:46:21 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

// static char	test_f(unsigned int i, char c)
// {
// 	if (c >= '0' && c <= '8')
// 		return (c + 1);
// 	if (c >= 'a' && c <= 'z')
// 		return (c -= 32);
// 	return (c);
// }

// int	main(void)
// {
// 	const char	*s = "aa45tG";
// 	char		*new_s;

// 	new_s = ft_strmapi(s, test_f);
// 	if (new_s == NULL)
// 		return (1);
// 	printf("%s: %s\n", s, new_s);
// 	free(new_s);
// }
