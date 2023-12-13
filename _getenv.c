#include "main.h"

/**
 * _getenv - get the environment variable.
 * @var: var to detect.
 * Return: array pointer.
 */

char *_getenv(const char *var)
{
	int ind, len;

	len = _strlen(var);
	for (ind = 0; environ[ind]; ind++)
	{
		if (_strncmp(var, environ[ind], len) == 0)
			return (environ[ind]);
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
