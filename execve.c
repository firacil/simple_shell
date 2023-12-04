#include "main.h"

int _execve(char **av)
{
	char *command = NULL;
	char *actual = NULL;

	if (av)
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
	return (0);
}
