#include "shell.h"

/**
 * print_err - print messge on std err
 * @cmd: command name
 * @txt: err message to print
 */
void print_err(char *cmd, char *txt)
{
	int i;

	if (cmd != NULL)
	{
		i = 0;
		while (cmd[i] != '\0')
		{
			write(2, &cmd[i], 1);
			i++;
		}
	}

	if (txt != NULL)
	{
		i = 0;
		while (txt[i] != '\0')
		{
			write(2, &txt[i], 1);
			i++;
		}
	}
}
