/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/20 14:59:20 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static void	leaks_end(void)
// {
// 	system("leaks minishell");
// }

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_token			*token;
	t_expression	*expr;
	t_env			*env;
	char			**args;

	(void)argv;
	(void)argc;
	env = init_env(envp);
	input = readline(PROMPT);
	while (1)
	{
		if (*input)
		{
			token = parse_token(input);
			if (token == NULL)
			{
				free_token(token);
				return (0);
			}
			// print_token(token);
			expr = parse_expression(token, NULL, env);
			// print_expression(expr, 0);
			if (expr == NULL)
			{
				free_token(token);
				free_expression(expr);
				return (0);
			}
			print_expression(expr, 0);
			args = list_to_arr(expr->args);
			ft_print_strs(args, 1);
			execute(args, env);
			add_history(input);
		}
		free(input);
		input = readline(PROMPT);
	}
	free_token(token);
	free_expression(expr);
	// atexit(leaks_end);
	return (0);
}
