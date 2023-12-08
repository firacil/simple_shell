#include "main.h"

/**
  * _token - a function that tokenize a string
  * @line: a pointer to a string to tokenize
  * @tokens: pointer to array of pointer return the array of tokens
  *
  * Return: number of tokens
  */

int _token(char *line, char **tokens)
{
	int count = 0;
	char *token = NULL;
	const char *delim = " \n";

	token = strtok(line, delim);

	while (token != NULL)
	{
		tokens[count] = strdup(token);

		if (tokens[count] == NULL)
		{
			perror("strdup failed");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;

	if (token == NULL && count == 0)
	{
		free(tokens);
		return (-1);
	}
	return (count);
}
