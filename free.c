#include "main.h"

void _free(char **s)
{
	size_t len = 0, i;

	if (s != NULL)
	{
		len = _strlen(*s);
		for (i = 0; i < len; i++)
			free(s[i]);
	}
}
