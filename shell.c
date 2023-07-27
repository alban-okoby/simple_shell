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
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		usrinput = readline();
		parsedtxt = parse(usrinput);
		stat = cmdexe(parsedtxt);

		free(usrinput);
		free(parsedtxt);
	} while (stat);

	return (stat);
}
