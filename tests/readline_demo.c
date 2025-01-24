/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_demo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:39:31 by lseeger           #+#    #+#             */
/*   Updated: 2025/01/24 15:38:19 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stdio
#include <stdio.h>

// rest
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*input;

	printf("Welcome to the Readline demo. Type 'exit' to quit.\n");
	while (1)
	{
		// Use readline to get input from the user
		input = readline(">>> ");
		if (!input)
		{
			// If input is NULL (Ctrl+D), exit the loop
			printf("\nExiting... Goodbye!\n");
			break ;
		}
		// Exit condition
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			printf("Exiting... Goodbye!\n");
			break ;
		}
		// Add input to history
		add_history(input);
		// Handle special "replace" command
		if (strcmp(input, "replace") == 0)
		{
			rl_replace_line("This line has been replaced.", 0);
			rl_redisplay(); // Refresh display after replacing the line
			free(input);
			continue ;
		}
		// Handle "clear_history" command
		if (strcmp(input, "clear_history") == 0)
		{
			rl_clear_history();
			printf("History cleared.\n");
			free(input);
			continue ;
		}
		// Print the entered input
		printf("You entered: %s\n", input);
		// Prepare readline for new input
		rl_on_new_line();
		// Free the memory allocated by readline
		free(input);
	}
	return (0);
}
