/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:22:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 12:52:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_token(t_token *token)
{
	ft_putstr_fd("Tokens:\n", STDOUT_FILENO);
	while (token)
	{
		ft_write_insertion(1);
		print_token_type(token->type);
		if (token->type == TOKEN_END)
			ft_putstr("\n");
		else
		{
			ft_putstr(": ");
			if (token->str)
				ft_putstr(token->str);
			else
				ft_putstr("NULL");
			ft_putchar('\n');
		}
		token = token->next;
	}
}
