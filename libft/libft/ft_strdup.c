/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:30:43 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:45:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*new_str;
	const int	s_len = ft_strlen(s);

	new_str = malloc(sizeof(char) * (s_len) + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, s_len + 1);
	return (new_str);
}
