#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \n\t\r\a"

extern char **environ;

char *readline(void);
char **parse(char *line);
int cmdexe(char **txt);

#endif
