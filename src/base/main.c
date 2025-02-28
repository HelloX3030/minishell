/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/28 12:36:13 by lkubler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	main(int argc, char **argv, char **envp)
{
	char			*input;
	t_token			*token;
	t_expression	*expr;
	t_env			*env;
	char			**args;

	(void)argv;
	(void)argc;
	(void)expr;
	if (!init_shell(&env, envp))
		return (1);
	input = readline(PROMPT);
	while (1)
	{
		if (*input)
		{
			token = parse_token(input);
			if (!token)
				return (free(input), 0);
			// print_token(token);
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
			//print_expression(expr, 0);
			// print_expression_args(expr);
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
			// printf("args:\n");
			// ft_print_strs(args, 0);
			execute(args, env);
			add_history(input);
			free_token(token);
			free_expression(expr);
		}
		free(input);
		input = readline(PROMPT);
	}
	return (0);
}
