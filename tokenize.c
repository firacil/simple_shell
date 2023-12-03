#include "main.h"

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
