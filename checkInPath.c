#include "shell.h"

/**/
PathInfo absolutepath(char *txt)
{
	PathInfo info = {0, ""};

	if (access(txt, F_OK) == 0)
	{
		info.exists = 1;
		strncpy(info.fullpath, txt, BUFSIZE);
	}
	return (info);
}

/**/
PathInfo relativepath(char *txt)
{
	PathInfo info = {0, ""};
	char *cwd = getcwd(NULL, 0);
	char fullpath[BUFSIZE];

	if (cwd == NULL)
	{
		perror("Eroor: getcwd");
		return (info);
	}
	
	snprintf(fullpath, sizeof(fullpath), "%s/%s", cwd, txt);
	free(cwd);

	if (access(fullpath, F_OK) == 0)
	{
		info.exists = 1;
		strncpy(info.fullpath, fullpath, BUFSIZE);
	}
	return (info);
}

/**/
PathInfo searchInPath(char *target, char *env_path)
{
	PathInfo result = {0, ""};
	char *path_copy = strdup(env_path);
	char *dir = strtok(path_copy, ":");
	char fullpath[BUFSIZE];

	if (env_path != NULL)
	{
		while (dir != NULL)
		{
			snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, target);
			if (access(fullpath, F_OK) == 0)
			{
				result.exists = 1;
				strncpy(result.fullpath, fullpath, BUFSIZE);
				break;
			}
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	 return (result);
}
/**
 * checkInPath - Check is user command is in the PATH
 * @txt: the command
 *
 * Return: Info about path
 */
PathInfo checkInPath(char *txt)
{
	PathInfo result = {0, ""};
	char *env_path = getenv("PATH");

	if (txt == NULL || txt[0] == '\0')
		return (result);
	if (txt[0] == '/')
	{
		result = absolutepath(txt);
		return (result);
	}
	else
	{
		result = relativepath(txt);
		if (result.exists)
			return (result);
	}
	return (searchInPath(txt, env_path));
}
