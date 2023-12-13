#ifndef _SHELL_H
#define _SHELL_H

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
extern char **environ;

int _printenv(void);
char *_getenv(char *var);

char *command_path(char *cmd);

#endif
