/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:11:47 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/10 15:01:10 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	init_minishell(t_minishell *ms, char **envp)
{
	if (!envp || !*envp)
		ms->env = init_essentials();
	else
	{
		ms->env = init_env(envp);
		handle_lvl(&ms->env);
	}
	if (!ms->env && (envp && *envp))
		exit(EXIT_FAILURE);
	ms->input = NULL;
	ms->token = NULL;
	ms->expr = NULL;
}
