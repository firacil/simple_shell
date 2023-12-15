#include "main.h"

/**
  * _execve - a function execute command that pass to it
  * @av: a pointer to an array of pointers held the command
  * @first: double pointer to begin of args.
  * Return: error code or Alawys 0.
  */
int _execve(char **av, char **first)
{
	pid_t my_child;
	int stat, flag = 0, ret = 0;
	char *command = av[0];

	if (command[0] != '/' && command[0] != '.')
		flag = 1, command = getpath(command);
	if (!command || (access(command, F_OK) == -1))
	{
		if (errno == EACCES)
			ret = (_error(av, 126));
		else
			ret = (_error(av, 127));
	}
	else
	{
		my_child = fork();
		if (my_child == -1)
		{
			if (flag)
				free(command);
			perror("Error child:");
			return (1);
		}
		if (my_child == 0)
		{
			execve(command, av, environ);
			if (errno == EACCES)
				ret = (_error(av, 126));
			f_env(), free_args(av, first), free_alias(aliases);
			_exit(ret);
		}
		else
		{
			wait(&stat);
			ret = WEXITSTATUS(stat);
		}
	}
	if (flag)
		free(command);
	return (ret);
}
