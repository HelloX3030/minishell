/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:11:47 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/11 12:35:17 by lseeger          ###   ########.fr       */
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
	ms->status = 0;
	ms->heredoc_count = 0;
}
