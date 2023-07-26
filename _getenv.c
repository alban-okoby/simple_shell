#include "shell.h"

/**
 * _getenv - custun getenv function
 * @name: variable to get in environment
 *
 * Return: pointer to char
 */
char *_getenv(const char *name)
{
	int i;
	char *equals;
	int name_length;

	for (i = 0; environ[i] != NULL; i++)
	{
		equals = _strchr(environ[i], '=');
		if (equals == NULL)
			continue;
		name_length = equals - environ[i];
		if (_strncmp(environ[i], name, name_length) == 0)
			return (equals + 1);
	}
	return (NULL);
}
