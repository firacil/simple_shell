#include "main.h"

char *get_args(char *line, int *eret);
int call_args(char **args, char **front, int *eret);
int run_args(char **args, char **front, int *eret);
int han_args(int *eret);
int check_args(char **args);

/**
 * get_args - gets a command from stdin.
 * @line: a buffer to store the command.
 * @eret: return value of last executed command.
 * Return: NULL/ pointer to the stored command.
 */

char *get_args(char *line, int *eret)
{
	size_t n = 0;
	ssize_t read;
	char *prompt = "$ ";

	if (line)
		free(line);

	read = _getline(&line, &n, STDIN_FILENO);
	if (read == -1)
		return (NULL);
	if (read == 1)
	{
		hist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
		return (get_args(line, eret));
	}

	line[read - 1] = '\0';
	var_rep(&line, eret);

	return (line);
}

/**
 * call_args - partiton operator from command and calls them.
 * @args: an array of arguments.
 * @front: a double pointer to beginning of args.
 * @eret: return of value of parent process.
 * Return: return value of last exuted command.
 */

int call_args(char **args, char **front, int *eret)
{
	int ret, index;

	if (!args[0])
		return (*eret);
	for (index = 0; args[index]; index++)
	{
		if (_strncmp(args[index], "||", 2) == 0)
		{
			free(args[index]);
			args[index] = NULL;
			args = replace_alias(args);
			ret = run_args(args, front, eret);
			if (*eret != 0)
			{
				args = &args[++index];
				index = 0;
			}
			else
			{
				for (index++; args[index]; index++)
					free(args[index]);
				return (ret);
			}
		}
		if (_strncmp(args[index], "&&", 2) == 0)
		{
			free(args[index]);
			args[index] = NULL;
			args = replace_alias(args);
			ret = run_args(args, front, eret);
			if (*eret == 0)
			{
				args = &args[++index];
				index = 0;
			}
			else
			{
				for (index++; args[index]; index++)
					free(args[index]);
				return (ret);
			}
		}
	}
	args = replace_alias(args);
	ret = run_args(args, front, eret);
	return (ret);
}

/**
 * run_args - calls the execution of command.
 * @args: an array of arguments.
 * @front: double pointer to begin of args.
 * @eret: return value of parent process last excuted command.
 * Return: return value of last excuted command.
 */

int run_args(char **args, char **front, int *eret)
{
	int ret, i;
	int (*builtin)(char **args, char **front);

	builtin = get_builtin(args[0]);

	if (builtin)
	{
		ret = builtin(args + 1, front);
		if (ret != EXIT)
			*eret = ret;
	}
	else
	{
		*eret = _execve(args, front);
		ret = *eret;
	}

	hist++;

	for (i = 0; args[i]; i++)
		free(args[i]);

	return (ret);
}

/**
 * han_args - gets, calls and runs the excution of command.
 * @eret: return value of parent process last command.
 * Return: EOF / -1 / exit value
 */

int han_args(int *eret)
{
	int ret = 0, index;
	char **args, *line = NULL, **front;

	line = get_args(line, eret);
	if (!line)
		return (END_OF_FILE);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (ret);
	if (check_args(args) != 0)
	{
		*eret = 2;
		free_args(args, args);
		return (*eret);
	}
	front = args;

	for (index = 0; args[index]; index++)
	{
		if (_strncmp(args[index], ";", 1) == 0)
		{
			free(args[index]);
			args[index] = NULL;
			ret = call_args(args, front, eret);
			args = &args[++index];
			index = 0;
		}
	}
	if (args)
		ret = call_args(args, front, eret);

	free(front);
	return (ret);
}

/**
 * check_args - checks if there are any leading ';'...
 * @args: 2D pointer to tokenized commands and arguments.
 * Return: invalid or 0.
 */

int check_args(char **args)
{
	size_t i;
	char *cur, *nex;

	for (i = 0; args[i]; i++)
	{
		cur = args[i];
		if (cur[0] == ';' || cur[0] == '&' || cur[0] == '|')
		{
			if (i == 0 || cur[1] == ';')
				return (_error(&args[i + 1], 2));
			nex = args[i + 1];
			if (nex && (nex[0] == ';' || nex[0] == '&' || nex[0] == '|'))
				return (_error(&args[i + 1], 2));
		}
	}
	return (0);
}
