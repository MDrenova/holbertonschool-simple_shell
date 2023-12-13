#include "shell.h"

int main(void)
{
    char *cmd, *path, *path_var; 

	_printenv();

	path_var = _getenv("PATH");
    printf("Path variables\n %s\n", path_var);
    
    cmd = "ls";
    path = command_path(cmd);

    if (path != NULL)
    {
        printf("Full path for %s: %s\n", cmd, path);
        free(path); 
    } else {
        printf("Command %s not found.\n", cmd);
    }
    

	return 0;
}
