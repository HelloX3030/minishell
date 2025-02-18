/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_placeholder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:05:46 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/18 16:06:54 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

bool	is_cmd_placeholder(char *str)
{
	if (ft_strncmp(str, "cmd", 2) == 0 || ft_strncmp(str, "CMD", 2) == 0)
		return (true);
	return (false);
}
