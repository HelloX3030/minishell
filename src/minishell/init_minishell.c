/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:11:47 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/26 17:11:57 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_minishell(t_minishell *ms)
{
	ms->env = NULL;
	ms->input = NULL;
	ms->token = NULL;
	ms->expr = NULL;
	ms->stop_execution = false;
}
