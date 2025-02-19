/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/19 15:45:57 by lseeger          ###   ########.fr       */
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

	input = "cmd1 <input1.txt >cmd1 input.text > output1.txt > output2.txt ";
	printf("Input: %s\n", input);
	token = parse_token(input);
	print_token(token);
	expr = parse_expression(token, NULL);
	print_expression(expr, 0);
	execute_expression(expr);
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
