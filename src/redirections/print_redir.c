/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:20:48 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/08 15:27:27 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	print_redir_type(t_redir_type type)
{
	if (type == REDIR_IN)
		ft_putstr("REDIR_IN");
	else if (type == REDIR_OUT)
		ft_putstr("REDIR_OUTPUT");
	else if (type == REDIR_APPEND)
		ft_putstr("REDIR_APPEND");
	else
		ft_putstr("UNKNOWN");
}

void	print_redir(t_redir *redir, int insertion)
{
	if (!redir)
	{
		ft_write_insertion(insertion);
		ft_putstr("NULL\n");
		return ;
	}
	ft_write_insertion(insertion);
	print_redir_type(redir->type);
	ft_putstr(": ");
	ft_putstr(redir->file);
	ft_putstr("\n");
}
