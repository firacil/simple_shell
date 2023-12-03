#include "main.h"

/**
  * _execve - a function execute command that pass to it
  * @av: a pointer to an array of pointers held the command
  *
  * Return: Alawys 0
  */
int _execve(char **av)
{
	pid_t my_child;
	int status;

	my_child = fork();
	if (my_child == -1)
	{
		perror("Error");
		return (-1);
	}
	else if (my_child == 0)
	{
		if (execvp(av[0], av) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	return (0);
}
