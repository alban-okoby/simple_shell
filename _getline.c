#include "shell.h"

/**
 * _getline - This function s to
 * get userinput
 * Descrition : This function ..
 * Return: a string;
 */
char *_getline(void)
{
	int c;
	static char buffer[READLINE_BUFSIZE];
	int position = 0;
	int bufsize = 0;
	char *line = malloc(sizeof(char) * READLINE_BUFSIZE);

	if (!line)
	{
		fprintf(stderr, "Error: malloc");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (position >= bufsize)
		{
			bufsize = read(0, buffer, READLINE_BUFSIZE);
			if (bufsize <= 0)
			{
				line[position] = '\0';
				return (line);
			}
			position = 0;
		}
		c = buffer[position];

		if (c == '\n')
		{
			line[position] = '\0';
			position++;
			return (line);
		}
		line[position] = c;
		position++;
	}
}
