/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:21:57 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 15:53:45 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_token	*parse_token(char *str_start, char *str_end)
{
	t_token	*token;

	token = create_token();
	if (!token)
		return (NULL);
	// parsing logic
	token->str = ft_strdup(str_start);
	(void)str_end;
	return (token);
}
