#include "main.h"

/**
 * Description here..
 */

char *situation(char **argv)
{
	if (argv[0] == NULL)
	{
		;
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		myexit();
		return (NULL);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		cdd(argv);
		return (NULL);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		currentenv();
		return (NULL);
	}
	else
	{
		_execve(argv);
	}
	return (NULL);
}
