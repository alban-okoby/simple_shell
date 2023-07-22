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

/* BUILTINS 
int to_unset_alias(info_s *info, char *str);
int to_set_alias(info_s *info, char *str);
int to_print_alias(list_s *node);
int to_handle_alias(info_s *info);
int to_change_alias(info_s *info);
*/
#endif
