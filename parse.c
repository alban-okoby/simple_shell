#include "shell.h"

/**
 * parse - parse the line entered by user
 * transform it in a string without some delimiter
 * @line: the line entered by the user
 *
 * Return: A set of string terminated by NULL
 */
char **parse(char *line)
{
	/*64 is choosed arbitrary*/
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(sizeof(char *) * bufsize);
	char *token;

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	do {
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			busize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (tokens == NULL)
			{
				fprintf(stderr, "Error: realloc");
				exit(EXIT_FAILURE);
			}
		}
	} while (token = strtok(NULL, DELIM));
	tokens[position] = NULL;

	return (tokens);
}
