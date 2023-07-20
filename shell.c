#include "shell.h"

/**
 * main - main function for the shell
 * @argc: the number of arguments
 * @argv: The list of arguments
 * @envp: the environment
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[], char *envp)
{
	char *usrinput;
	char **parsedtxt;
	int stat;

	do {
		printf("#cisfin$ ");
		usrinput = readline();
		parsedtxt = parse(usrinput);
		stat = cmdexe(parsedtxt);
	} while (stat);

	free(usrinput);
	free(parsedtxt);

	return (0);
}
