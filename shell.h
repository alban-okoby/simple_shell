#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \n\t\r\a"
#define BUFSIZE 1024

extern char **environ;

char *readline(void);
char **parse(char *line);
int checkInPath(char *txt);
int cmdexe(char **txt);

/* BUILTINS*/
char *my_getline(void);
int get_cmd_env(void);
#endif
