#include "shell.h"

/**
 * handleVar - Replace spacial variable in the command
 * @command: The command entered by user
 * @status: The status of the last process executed
 *
 * Return: updated cmd with var replacements
 */
char *handleVar(char *command, int status)
{
	char *updatedCommand = (char *)malloc(BUFSIZE);
	char *temp;
	int i = 0;

	while (*command != '\0')
	{
		if (*command == '$')
		{
			if (*(command + 1) == '?' || *(command + 1) == '$')
			{
				/* Replace $? with the exit code of the last process */
				temp = intToString(WEXITSTATUS(status));
				_strncpy(updatedCommand + i, temp, BUFSIZE - i);
				i += strlen(temp);
				free(temp);
				command += 2;
			}
			else
			{
				/* If isn't a special var  */
				updatedCommand[i] = *command;
				i++;
				command++;
			}
		}
		else
		{
			updatedCommand[i] = *command;
			i++;
			command++;
		}
	}
	updatedCommand[i] = '\0'; /* Null end the updated command */
	return (updatedCommand);
}
