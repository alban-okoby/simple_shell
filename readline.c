#include "shell.h"

/**
 * readline - Function that will take user input
 *
 * Return: The text entered by the user
 */
char *readline(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error: readline");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
