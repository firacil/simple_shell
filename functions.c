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

/* functions that will be written in this file */

/* _strtok (eisra) */
/* _strcpy (eisra) */
/* _strlen (firaol) */
/* _strdup (firaol) */
/* _strcmp (firaol(done) */
