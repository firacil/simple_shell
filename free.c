#include "main.h"

/**
  * _free - a function frees
  * @s: pointer to array of pointer
  *
  * Return: Nothing
  */
void _free(char **s)
{
	size_t i;

	if (s != NULL)
	{
		for (i = 0; s[i] != NULL; i++)
		{
			free(s[i]);
		}

		free(s);
	}
}
