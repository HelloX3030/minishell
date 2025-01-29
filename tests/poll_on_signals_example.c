#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t	signal_received = 0;
		// Flag to indicate signal reception

// Signal handler to set the flag
void	sigint_handler(int sig)
{
	signal_received = 1; // Set flag to indicate SIGINT was received
}

// Function to check for the signal in the main loop
void	check_signal(void)
{
	if (signal_received)
	{
		printf("\nSIGINT received, but no immediate interruption.\n");
		signal_received = 0; // Reset flag after handling
	}
}

int	main(void)
{
	char	*input;

	// Set up signal handler for SIGINT (Ctrl+C)
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
	{
		perror("Signal setup failed");
		return (1);
	}
	while (1)
	{
		// Poll for the signal without blocking
		check_signal();
		// Read user input
		input = readline("myshell> ");
		if (input == NULL)
		{
			break ; // Exit loop on EOF (Ctrl+D)
		}
		if (*input)
		{
			add_history(input); // Add to history if input is not empty
		}
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break ; // Exit loop when "exit" command is entered
		}
		printf("You typed: %s\n", input);
		free(input); // Free input to avoid memory leak
	}
	rl_clear_history(); // Clear history before exiting
	return (0);
}
