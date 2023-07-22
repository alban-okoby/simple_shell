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
	int size = BUFSIZE;
	int position = 0;
	char **tokens = malloc(sizeof(char *) * size);
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

		if (position >= size)
		{
			size += 1024;
			tokens = realloc(tokens, size * sizeof(char *));
			if (tokens == NULL)
			{
				fprintf(stderr, "Error: realloc");
				exit(EXIT_FAILURE);
			}
		}
	} while ((token = strtok(NULL, DELIM)));
	tokens[position] = NULL;

	return (tokens);
}
