#include "shell.h"

/**
 * checkComment - Check if user type #
 * @parsedtxt: user unput parsed
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
