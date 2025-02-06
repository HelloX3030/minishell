/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:20:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 15:58:00 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_token(t_token *token)
{
	if (!token)
		return ;
	if (token->next)
		free_token(token->next);
	if (token->str)
		free(token->str);
	free(token);
}
