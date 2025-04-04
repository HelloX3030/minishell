/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:22:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/03 13:55:31 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_token(t_token *token)
{
	printf("Tokens:\n");
	while (token)
	{
		ft_printf_insertion(1);
		print_token_type(token->type);
		if (token->type == TOKEN_END)
			printf("\n");
		else
		{
			printf(": ");
			if (token->str)
				printf("%s\n", token->str);
			else
				printf("NULL\n");
		}
		token = token->next;
	}
}
