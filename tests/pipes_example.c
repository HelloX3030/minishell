#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	const char	*filename = "example.txt";
	int			pipefd[2];
	pid_t		pid;
	char		buffer[256];
	ssize_t		bytes_read;
	int			fd;
	int			status;

	// Create a pipe
	if (pipe(pipefd) == -1)
	{
		perror("Error creating pipe");
		exit(EXIT_FAILURE);
	}
	// Fork a child process
	pid = fork();
	if (pid < 0)
	{
		perror("Error forking process");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		// Child process
		close(pipefd[0]); // Close unused read end of the pipe
		// Open the file for reading
		fd = open(filename, O_RDONLY);
		if (fd < 0)
		{
			perror("Error opening file");
			close(pipefd[1]);
			exit(EXIT_FAILURE);
		}
		// Read data from the file and write it to the pipe
		while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
		{
			write(pipefd[1], buffer, bytes_read);
		}
		close(fd);        // Close the file
		close(pipefd[1]); // Close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		// Parent process
		close(pipefd[1]); // Close unused write end of the pipe
		printf("Parent process (PID: %d) reading data from child:\n", getpid());
		while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1)) > 0)
		{
			buffer[bytes_read] = '\0'; // Null-terminate the string
			printf("%s", buffer);
		}
		close(pipefd[0]); // Close the read end of the pipe
		// Wait for the child process to complete
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("\nChild exited with status: %d\n", WEXITSTATUS(status));
		}
		else
		{
			printf("Child process did not terminate normally.\n");
		}
	}
	return (0);
}
