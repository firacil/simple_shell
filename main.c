#include "main.h"

int main()
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
		
		count = _token(line, av);
		if (count > 0)
			_execve(av);
	}

	free(av);
	free(line);
	return (0);
}
