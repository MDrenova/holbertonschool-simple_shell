#include "shell.h"

int _printenv()
{
	int i, file_descr = 1;
	if (environ == NULL)
	{
		fprintf(stderr, "error");
	}

	i = 0;
	while(environ[i] != NULL)
	{
		write(file_descr, environ[i],strlen(environ[i]));
		write(file_descr, "\n", 1);
		i++;
	}
	return(0);
}
char *_getenv(char *var)
	{
	int i, len_var;
	if (environ == NULL)
	{
		fprintf(stderr, "environmet variable is null");
		return (NULL);
	
	}
	len_var = strlen(var);
	for (i = 0; environ[i] != NULL; i++)
	{
	if (strncmp(environ[i], var, len_var) == 0 )
		return (&environ[i][len_var]);
	}
	return (NULL);
}
