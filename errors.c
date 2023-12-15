#include "main.h"

int num_len(int num);
char *_itoa(int num);

/**
 * num_len - countes length of num.
 * @num: number to be counted.
 * Return: num length.
 */

int num_len(int num)
{
	unsigned int numb;
	int len = 1;

	if (num < 0)
	{
		len++;
		numb = num * -1;
	}
	else
	{
		numb = num;
	}
	while (numb > 9)
	{
		len++;
		numb /= 10;
	}

	return (len);
}

/**
 * _itoa - converts an integer to astring.
 * @num: integer to be converted.
 * Return: converted string.
 */

char *_itoa(int num)
{
	char *buffer;
	int len = num_len(num);
	unsigned int numb;

	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);

	buffer[len] = '\0';

	if (num < 0)
	{
		numb = num * -1;
		buffer[0] = '-';
	}
	else
	{
		numb = num;
	}

	len--;
	do {
		buffer[len] = (num % 10) + '0';
		numb /= 10;
		len--;
	} while (num > 0);

	return (buffer);
}

/**
 * _error - write a custom error to stderr.
 * @args: array of arguments.
 * @err: error value.
 * Return: error value.
 */

int _error(char **args, int err)
{
	char *error;

	switch (err)
	{
	case -1:
		error = err_env(args);
		break;
	case 1:
		error = err_1(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			error = err_2ex(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			error = err_2syntax(args);
		else
			error = err_2cd(args);
		break;
	case 126:
		error = err_126(args);
		break;
	case 127:
		error = err_127(args);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);
}
