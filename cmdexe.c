#include "shell.h"

/**
 * cmdexe - this function excecute th parsed input
 * @parsedtxt: the parsed user's input
 *
 * Return: 1 on success
 */
int cmdexe(char **parsedtxt)
{
	pid_t pid;
	PathInfo pathinfo;
	int i, status;
	/* char *updatedCommand = handleVar(parsedtxt[0], status); */

	checkComment(parsedtxt);
	pathinfo = checkInPath(parsedtxt[0]);
	/* parsedtxt[0] = updatedCommand; */

	if (pathinfo.exists)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error: fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			for (i = 0; parsedtxt[i] != NULL; i++)
			{
				parsedtxt[i] = replaceVar(parsedtxt[i], status);
			}
			if (execve(pathinfo.fullpath, parsedtxt, environ) == -1)
				print_err(parsedtxt[0], " :command not found\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}

		return (1);
	}
	else
	{
		if (parsedtxt[0] == NULL || *parsedtxt[0] == '\0')
			return (127);
		return (shellBuildIn(parsedtxt));
	}
}
