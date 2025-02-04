/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/04 12:59:15 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	leaks_end(void)
{
	system("leaks minishell");
}

int	main(void)
{
	char			*input;
	t_expression	*expressions;

	input = "cmd1 && (cmd2 || cmd3)";
	expressions = parse_expression(input);
	free_expression(expressions);
	atexit(leaks_end);
	return (0);
}

/*
readline code:
char		*input;

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
