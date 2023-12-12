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
		if (isatty(STDIN_FILENO))
			_puts("$ ");

		read = _getline(&line, &len);
		av = malloc(sizeof(char *) * read);
		if (av == NULL)
			exit(EXIT_FAILURE);

		if (read <= 0)
		{
			free(line);
			_free(av);
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
		if (count >= 0)
			situation(av);

		_free(av);
	}
	_free(av);
	free(line);
	return (0);
}
