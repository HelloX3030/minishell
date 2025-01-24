/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:33:01 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:42:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*new_memory;

	new_memory = malloc(nmemb * size);
	if (new_memory == NULL)
		return (NULL);
	ft_bzero(new_memory, size * nmemb);
	return (new_memory);
}
