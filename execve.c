#include "main.h"

/**
  * _execve - a function execute command that pass to it
  * @av: a pointer to an array of pointers held the command
  *
  * Return: Alawys 0
  */
int _execve(char **av)
{
<<<<<<< HEAD
	char *command = NULL;
	char *actual = NULL;
=======
	pid_t my_child;
	int status;
>>>>>>> a672de6063de7f4c4162db7fd79b7761a56e75ba

	if (av)
	{
<<<<<<< HEAD
		pid_t my_child;
		int status;

		my_child = fork();
		if (my_child == -1)
=======
		perror("Error");
		return (-1);
	}
	else if (my_child == 0)
	{
		if (execvp(av[0], av) == -1)
>>>>>>> a672de6063de7f4c4162db7fd79b7761a56e75ba
		{
			perror("Error");
			return (-1);
		}
		else if (my_child == 0)
		{
			command = av[0];
			actual = getpath(command);

			if (execve(actual, av, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(my_child, &status, 0);
		}
	}
<<<<<<< HEAD
=======
	wait(&status);
>>>>>>> a672de6063de7f4c4162db7fd79b7761a56e75ba
	return (0);
}
