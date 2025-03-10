/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:11:47 by lseeger           #+#    #+#             */
/*   Updated: 2025/03/05 13:56:32 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_minishell(t_minishell *ms, char **envp)
{
	ms->env = init_env(envp);
	handle_lvl(&ms->env);
	if (!ms->env && (envp && *envp))
		exit(EXIT_FAILURE);
	ms->input = NULL;
	ms->token = NULL;
	ms->expr = NULL;
}
