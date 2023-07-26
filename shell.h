#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <stddef.h>

#define DELIM " \n\t\r\a"
#define BUFSIZE 1024

/**
 * struct a - information on path
 * @exists: existence of path
 * @fullpath: full path
 *
 * Description: Longer descrition
 */
struct a
{
	int exists;
	char fullpath[BUFSIZE];
};

/**
 * PathInfo - typedef for struct
 */
typedef struct a PathInfo;

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
char *handleVar(char *command, int status);

/* Custum functions*/
char *_strncpy(char *dest, char *src, size_t n);
char *custom_concat(char *str1, char *str2, char separator);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *s);
char *intToString(int num);

#endif
