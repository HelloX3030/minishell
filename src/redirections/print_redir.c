/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:20:48 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/25 14:51:54 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_redir_type(t_redir_type type)
{
	if (type == REDIR_IN)
		printf("REDIR_IN");
	else if (type == REDIR_OUT)
		printf("REDIR_OUTPUT");
	else if (type == REDIR_APPEND)
		printf("REDIR_APPEND");
	else
		printf("UNKNOWN");
}

void	print_redir(t_redir *redir, int insertion)
{
	if (!redir)
	{
		ft_printf_insertion(insertion);
		printf("NULL\n");
		return ;
	}
	ft_printf_insertion(insertion);
	print_redir_type(redir->type);
	printf(": %s\n", redir->file);
}
