#include "main.h"

<<<<<<< HEAD
=======
/**
  * main - Entry point
  *
  * Return: Always 0
  */
>>>>>>> a672de6063de7f4c4162db7fd79b7761a56e75ba
int main(void)
{
	char *line = NULL, **av = NULL;
	size_t len = 0;
	ssize_t read, i;
	int count = 0;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		av = malloc(sizeof(char *) * read);
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
<<<<<<< HEAD

=======
>>>>>>> a672de6063de7f4c4162db7fd79b7761a56e75ba
		count = _token(line, av);

		situation(av);
	}
	free(av);
	free(line);
	return (0);
}
