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
	int i, len = _strlen(src);
	char *dup = (char *)malloc(len + 1);

	if (src == NULL)
	{
		return (NULL);
	}

	if (dup == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		dup[i] = src[i];
	}
	dup[len] = '\0';

	return (dup);
}

/**
  * _strcpy - a function that copies the string
  * @s: the string
  *
  * Return: A pointer to the copied string
  */
char *_strcpy(const char *s)
{
	size_t i, len = 0;
	char *cpy;

	len = 1 + _strlen(s);
	cpy = malloc(len * sizeof(char));
	if (cpy == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		cpy[i] = s[i];

	cpy[len] = '\0';
	return (cpy);
}
