#include "main.h"

/**
 * Description
 */

void myexit(void)
{
	exit(0);
}

/**
 * description here
 */

void cdd(char **argv)
{
	if (argv[1] == NULL)
	{
		;
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("cd");
		}
	}
}

/**
 * descrption here
 */

void currentenv(void)
{
	char **env = environ;

	for (env; *env != NULL; env++)
	{
		_puts(*env);
	}
}
