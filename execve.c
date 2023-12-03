#include "main.h"

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
		if (execve(av[0], av, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	wait(&status);
        return (0);
}
