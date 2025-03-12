/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:20:48 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 18:02:25 by lseeger          ###   ########.fr       */
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
	char	*insertion_str;

	insertion_str = ft_get_insertion(insertion);
	if (!redir)
	{
		printf("%sNULL\n", insertion_str);
		free(insertion_str);
		return ;
	}
	printf("%s", insertion_str);
	print_redir_type(redir->type);
	printf(": %s\n", redir->file);
	free(insertion_str);
}
