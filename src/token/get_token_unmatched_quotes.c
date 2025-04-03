/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_unmatched_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:34 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/03 16:43:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

bool	get_token_unmatched_quotes(t_token *token)
{
	while (token)
	{
		if (token->type == TOKEN_UNMATCHED_QUOTES)
			return (true);
		token = token->next;
	}
	return (false);
}
