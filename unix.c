#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - A simple UNIX command line interpreter.
 * This is a very basic shell that reads a command from standard input and
 * executes it. It does not handle all the features of a typical shell.
 * It is a starting point for building a more complex shell.
 *
 * Return: 0 on success, 1 on error.
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *argv[2];
	pid_t pid;

	while (1) {
		printf("#cisfun$ ");
		read = getline(&line, &len, stdin);
		if (read == -1) {
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		line[read - 1] = '\0';  /* Remove newline character */

		pid = fork();
		if (pid == -1) {
			perror("Error:");
			return (1);
		}
		if (pid == 0) {
			argv[0] = line;
			argv[1] = NULL;
			if (execve(line, argv, NULL) == -1) {
				perror("./shell");
			}
		} else {
			wait(NULL);
		}
	}
	free(line);
	return (0);
}

