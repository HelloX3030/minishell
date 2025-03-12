/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:26:59 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/10 17:27:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_redir(void *redir)
{
	t_redir	*tmp;

	tmp = (t_redir *)redir;
	free(tmp->file);
	free(tmp);
}
