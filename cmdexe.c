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

	if (checkInPath(parsedtxt[0]))
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Error: fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if (execvp(parsedtxt[0], parsedtxt) == -1)
				fprintf(stderr, "%s: command not found\n", parsedtxt[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}

		return (1);
	}
	else
	{
		fprintf(stderr, "%s: commnd not found\n", parsedtxt[0]);
		return (1);
	}
}
