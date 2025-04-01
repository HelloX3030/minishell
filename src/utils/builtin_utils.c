/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:16:41 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/01 14:35:08 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	cd_error(char *args)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(args, 2);
	ft_putstr_fd(": ", 2);
	perror("");
}
