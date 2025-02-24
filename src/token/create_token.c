/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:20:54 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/24 15:30:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_token	*create_token(t_token_type type, char **str, char *str_end)
{
	char	*new_str;
	t_token	*token;

	if (!*str || !str_end)
		return (NULL);
	new_str = ft_strdupn(*str, str_end);
	if (!new_str)
		return (NULL);
	*str = str_end;
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->str = new_str;
	token->next = NULL;
	return (token);
}
