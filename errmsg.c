#include "main.h"


/**
 * err_env - creates error for _env builtin errors.
 * @args: an array of arguments passed to command.
 * Return: error string.
 */

char *err_env(char **args)
{
	char *err, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hist_str);
	_strcat(err, ": ");
	_strcat(err, args[0]);
	_strcat(err, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (err);
}

/**
 * err_1 - creates an err message for shell alias.
 * @args: array of arguments passed to the command.
 * Return: error string.
 */

char *err_1(char **args)
{
	char *err;
	int len;

	len = _strlen(name) + _strlen(args[0]) + 13;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
		return (NULL);

	_strcpy(err, "alias: ");
	_strcat(err, args[0]);
	_strcat(err, " not found\n");

	return (err);
}

/**
 * err_2ex - print error for exit builtin errs.
 * @args: an array of arguments passed to command.
 * Return: error string.
 */

char *err_2ex(char **args)
{
	char *err, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hist_str);
	_strcat(err, ": exit: Illegal number: ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(hist_str);
	return (err);
}

/**
 * err_2cd - creates an err message for cd errors.
 * @args: argument pass to command.
 * Return: err string.
 */

char *err_2cd(char **args)
{
	char *err, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	err = malloc(sizeof(char) * (len = 1));
	if (!err)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hist_str);
	if (args[0][0] == '-')
		_strcat(err, ": cd: Illegal option ");
	else
		_strcat(err, ": cd: can't cd to ");
	_strcat(err, args[0]);
	_strcat(err, "\n");

	free(hist_str);
	return (err);
}

/**
 * err_2syntax - print err when not command found.
 * @args: argument passed.
 * Return: exit value.
 */

char *err_2syntax(char **args)
{
	char *err, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hist_str);
	_strcat(err, ": Syntax error: \"");
	_strcat(err, args[0]);
	_strcat(err, "\" unexpected\n");

	free(hist_str);
	return (err);
}
