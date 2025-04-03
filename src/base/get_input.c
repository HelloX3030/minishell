/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:05 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/03 17:13:33 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	handle_expr_type(t_expression_type type, char **prompt)
{
	if (type == EXPR_UNCLOSED_GROUP)
		return (*prompt = PROMPT_GROUP, EXIT_CONTINUE);
	if (type == EXPR_UNCLOSED_AND)
		return (*prompt = PROMPT_AND, EXIT_CONTINUE);
	if (type == EXPR_UNCLOSED_OR)
		return (*prompt = PROMPT_OR, EXIT_CONTINUE);
	if (type == EXPR_UNCLOSED_PIPE)
		return (*prompt = PROMPT_PIPE, EXIT_CONTINUE);
	return (EXIT_SUCCESS);
}

static int	get_new_input(t_minishell *ms, char **prompt)
{
	char				*tmp;
	t_expression_type	type;

	if (!ms->input)
		ms->input = ft_strdup("");
	if (!ms->input)
		return (EXIT_FAILURE);
	tmp = readline(*prompt);
	if (!tmp)
		return (EXIT_FAILURE);
	ft_strjoin_inplace(&ms->input, tmp);
	if (free(tmp), !ms->input)
		return (EXIT_FAILURE);
	free_token(ms->token);
	ms->token = parse_token(ms->input);
	if (!ms->token)
		return (EXIT_FAILURE);
	if (get_token_unmatched_quotes(ms->token))
		return (*prompt = PROMPT_QUOTE, EXIT_CONTINUE);
	free_expression(ms->expr);
	ms->expr = parse_expression(ms->token, NULL, ms->env);
	if (!ms->expr)
		return (EXIT_FAILURE);
	type = get_expression_error(ms->expr);
	return (handle_expr_type(type, prompt));
}

int	get_input(t_minishell *ms)
{
	int		exit_code;
	char	*prompt;

	prompt = PROMPT;
	exit_code = get_new_input(ms, &prompt);
	while (exit_code == EXIT_CONTINUE)
		exit_code = get_new_input(ms, &prompt);
	return (exit_code);
}
