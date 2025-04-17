/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:05:05 by lkubler           #+#    #+#             */
/*   Updated: 2025/04/17 14:59:06 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

static int	handle_input(t_minishell *ms, char **prompt)
{
	t_expression_type	type;

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
	if (type == EXPR_SYNTAX_ERROR)
		return (EXIT_SUCCESS);
	else if (type == EXPR_UNCLOSED_GROUP)
		return (*prompt = PROMPT_GROUP, EXIT_CONTINUE);
	else if (type == EXPR_UNCLOSED_AND)
		return (*prompt = PROMPT_AND, EXIT_CONTINUE);
	else if (type == EXPR_UNCLOSED_OR)
		return (*prompt = PROMPT_OR, EXIT_CONTINUE);
	else if (type == EXPR_UNCLOSED_PIPE)
		return (*prompt = PROMPT_PIPE, EXIT_CONTINUE);
	return (EXIT_SUCCESS);
}

static int	get_new_input(t_minishell *ms, char *prompt)
{
	char	*tmp;

	tmp = readline(prompt);
	if (!tmp)
		return (EXIT_FAILURE);
	if (!ms->input)
		return (ms->input = tmp, EXIT_SUCCESS);
	ft_strjoin_inplace(&ms->input, "\n");
	if (!ms->input)
		return (free(tmp), EXIT_FAILURE);
	ft_strjoin_inplace(&ms->input, tmp);
	free(tmp);
	if (!ms->input)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_input(t_minishell *ms)
{
	int		exit_code;
	char	*prompt;

	prompt = PROMPT;
	if (ms->status != 0)
		prompt = PROMPT_FAILURE;
	sigmode_interactive();
	reset_sigint();
	exit_code = EXIT_CONTINUE;
	while (exit_code == EXIT_CONTINUE)
	{
		exit_code = get_new_input(ms, prompt);
		if (get_sigint())
			return (EXIT_SUCCESS);
		if (exit_code == EXIT_FAILURE)
			return (EXIT_FAILURE);
		exit_code = handle_input(ms, &prompt);
	}
	return (exit_code);
}
