/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_has_syntax_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:55:34 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/24 16:55:46 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

bool	token_has_syntax_error(t_token *token)
{
	while (token)
	{
		if (token->type == TOKEN_SYNTAX_ERROR)
			return (true);
		token = token->next;
	}
	return (false);
}
