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
		count++;
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	return (count);
}
