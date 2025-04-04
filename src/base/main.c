/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/04/03 13:45:17 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

inline static void	handle_token_syntax_error(t_minishell *ms)
{
	printf("Token Syntax error\n");
	free_token(ms->token);
	ms->token = NULL;
}

inline static void	handle_expression_syntax_error(t_minishell *ms)
{
	printf("Expression Syntax error\n");
	free_token(ms->token);
	ms->token = NULL;
	free_expression(ms->expr);
	ms->expr = NULL;
}

/*
	- manages ms.token and ms.expr
		=> needs to also free them
*/
static void	handle_input(t_minishell *ms)
{
	ms->token = parse_token(ms->input);
	if (!ms->token)
		return (free_minishell(ms), exit(EXIT_FAILURE));
	if (token_has_syntax_error(ms->token))
	{
		handle_token_syntax_error(ms);
		return ;
	}
	ms->expr = parse_expression(ms->token, NULL, ms->env);
	if (!ms->expr)
		return (free_minishell(ms), exit(EXIT_FAILURE));
	if (expression_has_syntax_error(ms->expr))
	{
		handle_expression_syntax_error(ms);
		return ;
	}
	execute_minishell(ms);
	free_token(ms->token);
	ms->token = NULL;
	free_expression(ms->expr);
	ms->expr = NULL;
}

/*
	- manages ms.input and ms.env
		=> needs to also free it
*/
int	main(int argc, char **argv, char **envp)
{
	t_minishell	ms;

	(void)argc;
	(void)argv;
	setup_interactive();
	init_minishell(&ms, envp);
	while (1)
	{
		ms.input = balance_input();
		if (!ms.input)
		{
			write(STDOUT_FILENO, "exit\n", 5);
			break ;
		}
		handle_input(&ms);
		add_history(ms.input);
		free(ms.input);
		ms.input = NULL;
	}
	return (free_minishell(&ms), EXIT_FAILURE);
}
