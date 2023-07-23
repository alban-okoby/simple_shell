#include "shell.h"

/**
 * main - main function for the shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *usrinput;
	char **parsedtxt;
	int stat;

	do {
		printf("$ ");
		/* usrinput = readline(); */
		usrinput = my_getline();
		parsedtxt = parse(usrinput);

		if (parsedtxt[0] != NULL)
		{
			if (strcmp(parsedtxt[0], "exit") == 0)
				stat = 0;
			else if (strcmp(parsedtxt[0], "env") == 0)
				stat = get_cmd_env(); /* Use get_cmd_env function */
			else
				stat = cmdexe(parsedtxt);
		}
		free(usrinput);
		free(parsedtxt);
	} while (stat);

	return (0);
}
