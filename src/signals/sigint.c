/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:51:21 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/17 14:54:40 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static volatile sig_atomic_t	*get_value(void)
{
	static volatile sig_atomic_t	sigint = 0;

	return (&sigint);
}

void	set_sigint(void)
{
	*get_value() = 1;
}

void	reset_sigint(void)
{
	*get_value() = 0;
}

bool	get_sigint(void)
{
	return (*get_value());
}
