#include "shell.h"

/**/
int exit_shell(char *command)
{
	int exit_code = atoi(command);

	if (command != NULL)
		return (exit_code);
	else
		return (0);
}

/**/
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

/**/
int change_dir(char *dir)
{
	char *homedir;
	char *previousdir;

	if (dir == NULL)
	{
		homedir = getenv("HOME");
		if (homedir != NULL)
		{
			if (chdir(homedir) != 0)
				perror("sh");
		}
		else
			fprintf(stderr, "sh: HOME environment variable not set\n");
	}
	else if (strcmp(dir, "-") == 0)
	{
		previousdir = getenv("OLDPWD");
		if (previousdir == NULL)
			fprintf(stderr, "sh: OLDPWD environment variable not set.\n");
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

	if (strcmp(parsedtxt[0], "exit") == 0)
		i = exit_shell(parsedtxt[1]);
	else if (strcmp(parsedtxt[0], "env") == 0)
		i = print_env();
	else if (strcmp(parsedtxt[0], "cd") == 0)
		i = change_dir(parsedtxt[1]);
	else
	{
		fprintf(stderr, "%s: command not found\n", parsedtxt[0]);
		i = 1;
	}

	return (i);
}
