/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:42:56 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/14 12:35:22 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*handle_wildcard(char *str_pos, int len, t_env *env,
		t_quote_type quote_type)
{
	char	*result;

	(void)env;
	(void)quote_type;
	// placeholder for wildcard handling
	str_pos++;
	result = ft_create_terminated_str(len + 1);
	if (!result)
		return (NULL);
	result[len] = '@';
	return (result);
}
