#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define DELIM " \n\t\r\a"
#define BUFSIZE 1024

typedef struct
{
	int exists;
	char fullpath[BUFSIZE];
} PathInfo;

extern char **environ;

char *readline(void);
char **parse(char *line);
PathInfo checkInPath(char *txt);
int cmdexe(char **txt);
int shellBuildIn(char **parsedtxt);
char *replaceVar(char *arg, int status);
char *_getline(void);
void checkComment(char **command);
void print_err(char *cmd, char *txt);

#endif
