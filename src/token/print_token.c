/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:22:53 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 15:54:13 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_token(t_token *token)
{
	char	*insertion_str;

	insertion_str = ft_get_insertion(1);
	printf("Tokens:\n");
	while (token)
	{
		printf("%sType:", insertion_str);
		print_token_type(token->type);
		printf("\n");
		if (token->str)
			printf("%sstr: %s\n", insertion_str, token->str);
		else
			printf("%sstr: NULL\n", insertion_str);
		token = token->next;
	}
	free(insertion_str);
}
