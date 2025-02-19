/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:12:01 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 15:41:03 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

bool	is_operator(char *str)
{
	return (ft_strncmp(str, "&&", 2) == 0 || ft_strncmp(str, "||", 2) == 0
		|| ft_strncmp(str, "|", 1) == 0);
}

int	is_redirection_operator(char *str)
{
	if (ft_strncmp(str, ">", 1) == 0 || ft_strncmp(str, "<", 1) == 0)
		return (1);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (2);
	else
		return (0);
}
