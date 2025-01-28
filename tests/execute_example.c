#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int		pipefd[2];
	pid_t	pid;
	char	buffer[128];
	ssize_t	bytesRead;
		char *args[] = {"/usr/bin/wc", "-l", "example.txt", NULL};
		int status;

	// Create a pipe
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	// Fork the process
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// Child process
		// Close the read end of the pipe
		close(pipefd[0]);
		// Redirect stdout to the write end of the pipe
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		// Close the original write end of the pipe
		close(pipefd[1]);
		// Prepare arguments for execve
		char *envp[] = {NULL}; // Environment variables (optional)
		// Execute the command
		execve(args[0], args, envp);
		// If execve fails
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		// Parent process
		// Close the write end of the pipe
		close(pipefd[1]);
		// Read the output from the read end of the pipe
		while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0)
		{
			buffer[bytesRead] = '\0'; // Null-terminate the string
			printf("%s", buffer);     // Print the output
		}
		// Close the read end of the pipe
		close(pipefd[0]);
		// Wait for the child process to finish
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			printf("Child exited with status %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("Child did not exit normally\n");
		}
	}
	return (0);
}
