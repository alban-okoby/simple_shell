#include "shell.h"

/**
 * replaceVar - Replace environment var
 * @arg: the argument following echo
 * @status: previous code exit code
 *
 * Return: the argument remplaced
 */
char *replaceVar(char *arg, int status)
{
	char *result = (char *)malloc(BUFSIZE);
	char *env_var = _getenv(arg + 1);
	char *str;

	if (arg[0] == '$')
	{
		if (_strcmp(arg, "$?") == 0)
		{
			str = intToString(WEXITSTATUS(status));
			_strncpy(result, str, BUFSIZE);
			/*snprintf(result, BUFSIZE, "%d", WEXITSTATUS(status));*/
			return (result);
		}
		else if (_strcmp(arg, "$$") == 0)
		{
			str = intToString(getpid());
			_strncpy(result, str, BUFSIZE);
			/*snprintf(result, BUFSIZE, "%d", getpid());*/
			return (result);
		}
		else
		{
			if (env_var != NULL)
				return (_strdup(env_var));
			return (_strdup(""));
		}
	}
	else
		return (_strdup(arg));
}
