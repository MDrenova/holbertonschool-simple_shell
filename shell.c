#include "shell.h"

/**
 * main - Main function of the shell.
 * @argc: The number of arguments.
 * @argv: The arguments.
 *
 * Return: 0 on success, or the error code on failure.
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

/**
 * command_read - Function to read a command and execute it.
 * @s: The command to read.
 * @name: the name of the program
 * Return: 0 on success, 2 if the command is "exit" or error code on failure.
 */
int command_read(char *s, char *name)
{
	int i;
	char *token = NULL;
	char *cmd_array[100];

	if (strcmp(s, "exit") == 0)
		return (2);
	if (strcmp(s, "env") == 0)
		return (_printenv());

	i = 0;
	token = strtok(s, " ");
	while (token != NULL && i < 100)
	{
		cmd_array[i++] = token;
		token = strtok(NULL, " ");
	}

	cmd_array[i] = NULL;

	return (execute(cmd_array, name));
}

/**
 * execute - Function to execute a command.
 * @cmd_arr: The command to execute.
 * @name: the name of the program
 * Return: 0 on success, or the error code on failure.
 */
int execute(char *cmd_arr[], char *name)
{
	pid_t pid;
	char *exe_path;
	int status;

	exe_path = command_path(cmd_arr[0]);
	if (exe_path == NULL)
	{
		fprintf(stderr, "%s: %s: not found", name, cmd_arr[0]);
		return (3);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Error....");
		return (-1);
	}

	if (pid > 0)
		wait(&status);
	else
	{
		if (environ)
		{
			execve(exe_path, cmd_arr, environ);
			exit(1);
		}
		else
		{
			execve(exe_path, cmd_arr, NULL);
			exit(1);
		}
	}

	free(exe_path);

	return (0);
}
