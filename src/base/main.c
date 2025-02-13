/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/13 14:46:10 by lseeger          ###   ########.fr       */
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

int	main(void)
{
	char			*input;
	t_token			*token;
	t_expression	*expr;
	t_token			*closing;

	// input = "cmd_first && ((cmd_a || cmd_b) && cmd_c) || cmd_d && cmd_e";
	input = "cmd &&) (cmd2 || cmd3) (last))";
	printf("Input: %s\n", input);
	token = parse_token(input);
	closing = get_closing_group(token->next->next);
	print_token(token);
	printf("Closing:\n");
	print_token(closing);
	expr = parse_expression(token, NULL);
	print_expression(expr, 0);
	free_token(token);
	free_expression(expr);
	// atexit(leaks_end);
	return (0);
}

/*
readline code:
char	*input;

	input = readline(PROMPT);
	while (input)
	{
		if (*input)
			add_history(input);
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break ;
		}
		printf("You typed: %s\n", input);
		free(input);
		input = readline(PROMPT);
	}
	rl_clear_history();
	return (0);
*/
