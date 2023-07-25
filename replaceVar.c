#include "shell.h"

/**
 *
 */
char *replaceVar(char *arg, int status)
{
	char *result = (char *)malloc(BUFSIZE);
	 char *env_var = getenv(arg + 1);

	if (arg[0] == '$')
	{
		if (strcmp(arg, "$?") == 0)
		{
			snprintf(result, BUFSIZE, "%d", WEXITSTATUS(status));
			return (result);
		}
		else if (strcmp(arg, "$$") == 0)
		{
			snprintf(result, BUFSIZE, "%d", getpid());
			return (result);
		}
		else
		{
			if (env_var != NULL)
				return (strdup(env_var));
			return (strdup(""));
		}
	}
	else
		return (strdup(arg));
}
