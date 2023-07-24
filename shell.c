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
		usrinput = readline();
		parsedtxt = parse(usrinput);
		stat = cmdexe(parsedtxt);

		free(usrinput);
		free(parsedtxt);
	} while (stat);

	return (0);
}
