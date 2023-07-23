#include "shell.h"

/**
 * get_cmd_env - This function print the current environment variables
 *
 * Return: Always returns 1 on success
 */
int get_cmd_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	return (1);
}
