#include "shell.h"

/**
 * exit_shell - Exit shell with code
 * @code: the code
 *
 * Return: the code
 */
int exit_shell(char *code)
{
	int exit_code;

	if (code != NULL)
	{
		exit_code = atoi(code);
		exit(exit_code);
	}
	else
		return (0);
}

/**
 * print_env - Print the environment
 *
 * Return: 1
 */
int print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (1);
}

/**
 * change_dir - Change directory
 * @dir:  the directory to change to
 *
 * Return: 1
 */
int change_dir(char *dir)
{
	char *homedir;
	char *previousdir;

	if (dir == NULL)
	{
		homedir = _getenv("HOME");
		if (homedir != NULL)
		{
			if (chdir(homedir) != 0)
				perror("sh");
		}
		else
		print_err(NULL, "sh: HOME environment variable not set\n");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		previousdir = _getenv("OLDPWD");
		if (previousdir == NULL)
			print_err(NULL, "sh: OLDPWD environment variable not set.\n");
		else
		{
			if (chdir(previousdir) != 0)
				perror("sh");
		}
	}
	else
	{
		if (chdir(dir) != 0)
			perror("sh");
	}

	return (1);
}
/**
 * shellBuildIn - Call shell buildin command
 * @parsedtxt: The command entered by user
 *
 * Return: 0 or 1 depending on the command
 */
int shellBuildIn(char **parsedtxt)
{
	int i = 0;

	if (_strcmp(parsedtxt[0], "exit") == 0)
		i = exit_shell(parsedtxt[1]);
	else if (_strcmp(parsedtxt[0], "env") == 0)
		i = print_env();
	else if (_strcmp(parsedtxt[0], "cd") == 0)
		i = change_dir(parsedtxt[1]);
	else
	{
		print_err("./hsh: 1: ", NULL);
		print_err(parsedtxt[0], " :not found\n");
		i = 127;
	}

	return (i);
}
