/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:29:52 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/03 15:29:11 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_token_type(t_token_type type)
{
	if (type == TOKEN_WORD)
		printf("TOKEN_WORD");
	else if (type == TOKEN_GROUP)
		printf("TOKEN_GROUP");
	else if (type == TOKEN_OPERATOR)
		printf("TOKEN_OPERATOR");
	else if (type == TOKEN_END)
		printf("TOKEN_END");
	else if (type == TOKEN_UNMATCHED_QUOTES)
		printf("TOKEN_UNMATCHED_QUOTES");
	else
		printf("UNKNOWN");
}
