#include "shell.h"

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 on success, 1 on failure
 */

int main(int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	size_t buf_size = 0;
	ssize_t characters = 0;

	name = argv[0];
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
		characters = getline(&line, &buf_size, stdin);
		if (characters == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		if (line[characters - 1] == '\n')
			line[characters - 1] = '\0';
		if (*line == '\0')
			continue;
		if (strcmp(line, "exit") == 0)
			break;
		if (command_read(line) == 2)
			break;
	}
	free(line);
	return (0);
}

/**
 * command_read - Reads a command from stdin
 * @s: The command to read
 * Return: 0 on success, 1 on failure
 */

int command_read(char *s)
{
	int i;
	char *token = NULL;
	char *cmd_array[100];

	if (strcmp(s, "exit") == 0)
		return (2);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' && s[i+1] == ' ')
			return (0);
	}
	if (strcmp(s, "env") == 0)
		return (_printenv());
	token = strtok(s, " ");
	i = 0;
	while (token != NULL && i < 100)
	{
		cmd_array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	cmd_array[i] = NULL;
	return (execute(cmd_array));
}

/**
 * execute - Executes a command
 * @cmd_arr: The command to execute
 * Return: 0 on success, 1 on failure
 */

int execute(char *cmd_arr[])
{
	pid_t pid;
	char *exe_path;
	int status;
	char *name;

	name = cmd_arr[0];
	exe_path = command_path(name);
	if (exe_path == NULL)
	{
		write(1, name, strlen(name));
		write(1, ": not found\n", 12);
		return (3);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error at creating a child process\n");
		return (-1);
	}
	if (pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				printf("Command '%s' failed with exit status %d\n", name, exit_status);
				return (exit_status);
			}
		}
	}
	else if (pid == 0)
	{
		execve(exe_path, cmd_arr, environ);
		perror("Error");
		exit(1);
	}
	free(exe_path);
	return (0);
}
