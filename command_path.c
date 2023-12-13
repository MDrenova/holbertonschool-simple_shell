#include "shell.h"

char *command_path(char *cmd)
{
	char *path, *path_copy, *full_path, *token;
	path = _getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Path variable not found");
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
	fprintf(stderr, "Error coping path");
	return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(strlen(token)+ strlen(cmd)+ 2);
		if (full_path == NULL)
		{
		fprintf(stderr, "Error allocating full path");
		free(path_copy);
		return (NULL);
		}
	strcpy(full_path, token);
	strcat(full_path, "/");
	strcat(full_path, cmd);
	
	token = strtok(NULL, ":");
	}
	free(path_copy);
	return(full_path);
}
