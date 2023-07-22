#include "shell.h"

/**
 * to_handle_exit - exits the shell
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 *
 * Return: exits with a given exit status (0)
 * if info->argv[0] != "exit"
 */
int to_handle_exit(info_s *info)
{
	int my_exitchecker = 0;

	if (info->argv[1])
	{
		my_exitchecker = err_num(info->argv[1]);
		if (my_exitchecker == -1)
		{
			info->status = 2;
			print_error(info, "Sorry, something went wrong ... Illegal number: ");
			puts_err(info->argv[1]);
			putchar_err('\n');
			return (1);
		}
		info->error_code = err_num(info->argv[1]);
		return (-2);
	}
	info->error_code = -1;
	return (-2);
}

/**
 * to_handle_cd - This function changes the current directory of the process
 * @info: contains simulated arguments, allowing 
 * for a consistent function prototype
 *
 * Return: 0
 */
int to_handle_cd(info_s *info)
{
	char *s, *dir, buffer[1024];
	int my_chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			my_chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			my_chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		my_chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		my_chdir_ret = chdir(info->argv[1]);

	if (my_chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		puts_err(info->argv[1]);
		putchar_err('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * to_handle_help - prints a message for a function not implemented
 * @info: contains simulated arguments for a function pointer,
 * constant function prototype.
 *
 * Return: Always 0
 */
int to_handle_help(info_s *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);

	return (0);
}

/**
 * to_handle_history - This function displays the history list, starting at 0.
 * @info: contains simulated arguments, constant function prototype.
 *
 * Return: Always 0
 */
int to_handle_history(info_s *info)
{
	print_list(info->history);

	return (0);
}

