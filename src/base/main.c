/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkubler <lkubler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:54:04 by lseeger           #+#    #+#             */
/*   Updated: 2025/02/07 12:28:08 by lkubler          ###   ########.fr       */
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
}
