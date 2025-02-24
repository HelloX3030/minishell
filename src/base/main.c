/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/24 16:58:52 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_token			*token;
	t_expression	*expr;
	t_env			*env;
	char			**args;

	(void)argv;
	(void)argc;
	(void)args;
	(void)expr;
	env = init_env(envp);
	input = readline(PROMPT);
	while (1)
	{
		if (*input)
		{
			token = parse_token(input);
			if (!token)
				return (free(input), 0);
			print_token(token);
			if (token_has_syntax_error(token))
			{
				printf("Token Syntax error\n");
				free_token(token);
				add_history(input);
				free(input);
				input = readline(PROMPT);
				continue ;
			}
			expr = parse_expression(token, NULL, env);
			if (!expr)
				return (free_token(token), free(input), 0);
			print_expression(expr, 0);
			if (expression_has_syntax_error(expr))
			{
				printf("Expression Syntax error\n");
				free_token(token);
				free_expression(expr);
				add_history(input);
				free(input);
				input = readline(PROMPT);
				continue ;
			}
			args = list_to_arr(expr->args);
			printf("args:\n");
			ft_print_strs(args, 1);
			// execute(args, env);
			add_history(input);
			free_token(token);
			free_expression(expr);
		}
		free(input);
		input = readline(PROMPT);
	}
	return (0);
}
