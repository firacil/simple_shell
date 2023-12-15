#include "main.h"

char **cpenv(void);
void f_env(void);
char **_getenv(const char *var);

/**
 * cpenv - creates a copy of the environment.
 * Return: If an error occurs - NULL / double pointer to new copy.
 */

char **cpenv(void)
{
	char **new_env;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;
	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_env[index] = malloc(_strlen(environ[index]) + 1);

		if (!new_env[index])
		{
			for (index--; index >= 0; index--)
				free(new_env[index]);
			free(new_env);
			return (NULL);
		}
		_strcpy(new_env[index], environ[index]);
	}
	new_env[index] = NULL;

	return (new_env);
}

/**
 * f_env - frees the environments copy.
 */
void f_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
 * _getenv - get the environment variable.
 * @var: var to detect.
 * Return: array pointer.
 */

char **_getenv(const char *var)
{
	int ind, len;

	len = _strlen(var);
	for (ind = 0; environ[ind]; ind++)
	{
		if (_strncmp(var, environ[ind], len) == 0)
			return (&environ[ind]);
	}
	return (NULL);
}

/**
 * _strncmp - compare two strings.
 * @s1: pointer to first string.
 * @s2: pointer to next string.
 * @n: first byte of strings to compare.
 * Return: success or fail.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
