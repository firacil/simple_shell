#include "main.h"

/**
  * main - Entry point
  *
  * Return: Always 0
  */

int main(void)
{
	char *line = NULL, **av = NULL;
	size_t len = 0;
	ssize_t read, i;
	int count = 0;

	while (1)
	{
		_puts("$ ");
		read = _getline(&line, &len);
		av = malloc(sizeof(char *) * MAX_READ);
		if (av == NULL)
			exit(EXIT_FAILURE);

		if (read == -1)
		{
			printf("\nExiting shell.\n");
			free(line);
			free(av);
			exit(EXIT_FAILURE);
		}

		for (i = 0; i < read; i++)
		{
			if (line[i] == '\n')
			{
				line[i] = '\0';
				break;
			}
		}
		count = _token(line, av);

		situation(av);

		int i;

		for (i = 0; i < count; i++)
		{
			free(av[i]);
		}

		/*free(av);*/
	}
	free (av);
	free(line);
	return (0);
}
