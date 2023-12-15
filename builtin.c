#include "main.h"

int _myexit(char **args, char **front);
int _cd(char **args, char __attribute__((__unused__)) **front);
/* intt _help(char **args, char __attribute__((__unused__)) **front); */


/**
 * get_builtin - matches a commandwith my builtin.
 * @command: command to match.
 * Return: function pointer to the correspondin builtin.
 */

int (*get_builtin(char *command))(char **args, char **front)
{
	builtint_t fun[] = {
		{ "exit", _myexit },
		{ "env", _env },
		{ "cd", _cd },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; fun[i].name; i++)
	{
		if (_strcmp(fun[i].name, command) == 0)
			break;
	}
	return (fun[i].f);
}

/**
 * _myexit - exits my shell.
 * @args: array of arguments contain exit val.
 * @front: double pointer to beginning of args.
 * Return: status val or fail
 */

int _myexit(char **args, char **front)
{
	int i, len_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_int && args[0][i] >= '0' && args[0][i] <= '9')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (_error(--args, 2));
	args -= 1;
	free_args(args, front);
	f_env();
	exit(num);
}

/**
 * _cd - changes current dir.
 * @args: array of arguments.
 * @front: double pointer to begin of args.
 * Return: not dir -2, err -1 or 0.
 */

int _cd(char **args, char __attribute__((__unused__)) **front)
{
	char **dir_info = NULL, *new_line = "\n";
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldpwd);
				return (_error(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (_setenv(dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (_setenv(dir_info, dir_info) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, new_line, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
	return (0);
}
