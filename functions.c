#include "main.h"

/**
  * _strcmp - a function that check length of string
  * @s1: a char type pointer to string one
  * @s2: a char type pointer to string two
  * Return: the difference in length
  */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}

	/* check length of the strings */

	return (*s1 - *s2);
}

/**
  * _strlen - a function that get the length of string
  * @s: the string
  * Return: the length of the string
  */
size_t _strlen(const char *s)
{
	size_t len = 0;

	if (s == NULL)
	{
		return (0);
	}

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
  * _strdup - a function that duplicate a given string
  * @src: the string
  * Return: a char type pointer point to the duplicated string
  */
char *_strdup(const char *src)
{
	size_t len;
	char *dup;

	if (src == NULL)
	{
		return (NULL);
	}
	len = _strlen(src);
	dup = malloc(len + 1);

	if (dup == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	else
	{
		_strcpy(dup, src);
	}

	return (dup);
}

/**
  * _strcpy - a function that copies the string
  * @src: the string to be copied.
  * @dest: string to be copied on.
  * Return: A pointer to the copied string
  */
char *_strcpy(char *dest, const char *src)
{
	char *org_dest = dest;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	while ((*dest++ = *src++) != '\0')
		;

	return (org_dest);
}
