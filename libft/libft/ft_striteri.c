/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hello_x <hello_x@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:40 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/11 10:17:13 by hello_x          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// #include "libft.h"

// static void	test_f(unsigned int i, char *c)
// {
// 	if (*c >= '0' && *c <= '8')
// 		*c += 1;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c -= 32;
// }

// int	main(void)
// {
// 	char	*s;

// 	s = ft_strdup("aa45tG");
// 	printf("%s: ", s);
// 	ft_striteri(s, test_f);
// 	printf("%s\n", s);
// 	free(s);
// 	return (0);
// }
