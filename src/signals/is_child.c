/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:37:16 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/15 14:13:01 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	*get_child(void)
{
	static int	child = -1;

	return (&child);
}

void	increase_child(void)
{
	(*get_child())++;
}

bool	is_child(void)
{
	return (*get_child());
}
