/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:42:56 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/14 13:27:38 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

char	*handle_wildcard(char *str_pos, int len, t_minishell *ms,
		t_quote_type quote_type)
{
	char	*result;

	(void)ms;
	(void)quote_type;
	// placeholder for wildcard handling
	str_pos++;
	result = ft_create_terminated_str(len + 1);
	if (!result)
		return (NULL);
	result[len] = '@';
	return (result);
}
