#include "shell.h"

/**
 * absolutepath - check for absolute pathname
 * @txt: user input
 *
 * Return: info about path
 */
PathInfo absolutepath(char *txt)
{
	PathInfo info = {0, ""};

	if (access(txt, F_OK) == 0)
	{
		info.exists = 1;
		_strncpy(info.fullpath, txt, BUFSIZE);
	}
	return (info);
}

/**
 * relativepath - check for reltive pathname
 * @txt: the user command
 *
 * Return: info about path
 */
PathInfo relativepath(char *txt)
{
	PathInfo info = {0, ""};
	char *cwd = getcwd(NULL, 0);
	char fullpath[BUFSIZE];
	char *str = custom_concat(cwd, txt, '/');

	if (cwd == NULL)
	{
		perror("Eroor: getcwd");
		return (info);
	}
	_strncpy(fullpath, str, BUFSIZE);
	free(cwd);
	free(str);

	if (access(fullpath, F_OK) == 0)
	{
		info.exists = 1;
		_strncpy(info.fullpath, fullpath, BUFSIZE);
	}
	return (info);
}

/**
 * searchInPath - Handle other case
 * @target: user input
 * @env_path: the path
 *
 * Return: info about path
 */
PathInfo searchInPath(char *target, char *env_path)
{
	PathInfo result = {0, ""};
	char *path_copy = _strdup(env_path);
	char *dir = strtok(path_copy, ":");
	char fullpath[BUFSIZE];
	char *str;

	if (env_path != NULL)
	{
		while (dir != NULL)
		{
			str = custom_concat(dir, target, '/');
			_strncpy(fullpath, str, BUFSIZE);
			free(str);
			if (access(fullpath, F_OK) == 0)
			{
				result.exists = 1;
				_strncpy(result.fullpath, fullpath, BUFSIZE);
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
	char *env_path = _getenv("PATH");

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
