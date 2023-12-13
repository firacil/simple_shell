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
	int count = 0, i;
	char *token = NULL;
	const char *delim = " \n";

	token = _strtok(line, delim);

	while (token != NULL)
	{
		tokens[count] = _strdup(token);

		if (tokens[count] == NULL)
		{
			perror("strdup failed");
			/*free(tokens);*/
			exit(EXIT_FAILURE);
		}
		count++;
		token = _strtok(NULL, delim);
	}

	for (i = 0; i < count; ++i)
	{
		if (tokens[i][0] == '#')
		{
			count = i;
			break;
		}
	}
	tokens[count] = NULL;

	if (token == NULL && count == 0)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (count);
}

/**
 * _atoi - converts string of charchters to integer.
 * @s: string charchter to be converted.
 * Return: result of _atoi
 */

int _atoi(const char *s)
{
	int res = 0;
	int sign = 1;

	/* skip leading whitespace */

	while (*s == ' ' || (*s >= 9 && *s <= 13))
	{
		s++;
	}

	/* handle sign */
	if (*s == '-' || *s == '+')
	{
		sign = (*s++ == '-') ? -1 : 1;
	}

	/* process each char until nondigit comes in */

	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s++ - '0');
	}

	/* applying sign */

	return (sign * res);
}
