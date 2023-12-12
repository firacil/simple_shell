#include "main.h"

/**
 * situation - a function check the enterd command
 * @argv: pointer to array of pointer holp the command
 * Return: a char type pointer
 */
int situation(char **argv)
{
	int ex_stat;

	if (argv[0] == NULL)
	{
		;
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		ex_stat = myexit(argv);
		return (ex_stat);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		change_dir(argv);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		currentenv();
	}
	else if (_strcmp(argv[0], "echo") == 0)
	{
		_echo(argv);
	}
	else
	{
		_execve(argv);
	}
	return (0);
}
