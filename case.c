#include "main.h"

/**
 * situation - a function check the enterd command
 * @argv: pointer to array of pointer holp the command
 * Return: a char type pointer
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
		change_dir(argv);
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
