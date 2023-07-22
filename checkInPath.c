#include "shell.h"

/**
 * checkInPath - Check is user command is in the PATH
 * @txt: the command
 *
 * Return: 1 if it's in 0 if not
 */
int checkInPath(char *txt)
{
	char *env_path = getenv("PATH");
	char *path_copy, *dir;
	char fullpath[BUFSIZE];
	char *cwd = getcwd(NULL, 0);

	/*check if it is a absolute pathname*/
	if (txt[0] == '/')
	{
		if (access(txt, F_OK) == 0)
			return (1);
		else
			return (0);
	}
	if (cwd == NULL)
	{
		perror("Error: getcwd");
		return (0);
	}
	snprintf(fullpath, sizeof(fullpath), "%s/%s", cwd, txt);
	free(cwd);
	if (access(fullpath, F_OK) == 0)
		return (1);
	if (env_path != NULL)
	{
		path_copy = strdup(env_path);
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{
			snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, txt);
			if (access(fullpath, F_OK) == 0)
			{
				free(path_copy);
				return (1);
			}
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (0);
}