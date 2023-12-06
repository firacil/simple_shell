#include "main.h"

/**
 * Descrption here
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
 * Description here
 */

int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/*
 * Description here
 */

char *_strdup(const char *src)
{
	if (src == NULL)
	{
		return (NULL);
	}

	int len = _strlen(src);

	char *dup = (char *)malloc(len + 1);

	if (dup == NULL)
	{
		return (NULL);
	}

	int i;

	for (i = 0; i < len; i++)
	{
		dup[i] = src[i];
	}
	dup[len] = '\0';

	return (dup);
}

/* functions that will be written in this file */

/* _strtok (eisra) */
/* _strcpy (eisra) */
/* _strlen (firaol) (done) */
/* _strdup (firaol) */
/* _strcmp (firaol(done) */
