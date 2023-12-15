#include "main.h"

int _env(char **args, char __attribute__((__unused__)) **front);
int _setenv(char **args, char __attribute__((__unused__)) **front);
/* int _unsetenv(char **args, char __attribute__((_unused__)) **front); */

/**
 * _env - prints the current env.
 * @args: array of arguments passed to call.
 * @front: double pointer to begin of args.
 * Return: err -1, success 0.
 */

int _env(char **args, char __attribute__((__unused__)) **front)
{
	int index;
	char nc = '\n';

	if (!environ)
		return (-1);
	for (index = 0; environ[index]; index++)
	{
		write(STDOUT_FILENO, environ[index], _strlen(environ[index]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}

/**
 * _setenv -changes or add environment var t PATH.
 * @args: array of arguments passed to shell.
 * @front: double pointer to begin of args.
 * Return: err -1 or success 0.
 */

int _setenv(char **args, char __attribute__((__unused__)) **front)
{
	char **env_var = NULL, **new_env, *new_val;
	size_t size;
	int index;

	if (!args[0] || !args[1])
		return (_error(args, -1));

	new_val = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_val)
		return (_error(args, -1));
	_strcpy(new_val, args[0]);
	_strcat(new_val, "=");
	_strcat(new_val, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_val;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_val);
		return (_error(args, -1));
	}

	for (index = 0; environ[index]; index++)
		new_env[index] = environ[index];

	free(environ);
	environ = new_env;
	environ[index] = new_val;
	environ[index + 1] = NULL;

	return (0);
}
