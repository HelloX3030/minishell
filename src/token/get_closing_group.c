/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closing_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:17:24 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/13 14:39:27 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_token	*get_closing_group(t_token *token)
{
	int	open_groups;

	if (!token || token->type != TOKEN_GROUP || ft_strcmp(token->str, "(") != 0)
		return (NULL);
	open_groups = 1;
	token = token->next;
	while (token)
	{
		if (token->type == TOKEN_GROUP)
		{
			if (ft_strcmp(token->str, "(") == 0)
				open_groups++;
			else if (ft_strcmp(token->str, ")") == 0)
				open_groups--;
			else
				return (NULL);
		}
		if (open_groups == 0)
			return (token);
		token = token->next;
	}
	return (NULL);
}
