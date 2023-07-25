#include "shell.h"

/**
 *
 */
void checkComment(char **parsedtxt)
{
	while (*parsedtxt != NULL)
	{
		if ((*parsedtxt)[0] == '#')
		{
			*parsedtxt = NULL;
			return;
		}
		parsedtxt++;
	}
}
