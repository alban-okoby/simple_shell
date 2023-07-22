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
	} while (stat);

	free(usrinput);
	free(parsedtxt);

	return (0);
}
