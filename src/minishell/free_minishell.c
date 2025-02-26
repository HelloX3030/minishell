/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:35:08 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/26 17:21:56 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

void	free_minishell(t_minishell *ms)
{
	free_env(ms->env);
	if (ms->input)
		free(ms->input);
	ms->input = NULL;
	free_token(ms->token);
	ms->token = NULL;
	free_expression(ms->expr);
	ms->expr = NULL;
}
