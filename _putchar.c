#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1, -1 otherwise
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - a function print a string
 * @s: the string
 *
 * Return: Nothing
 */
void _puts(const char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		write(STDOUT_FILENO, &s[i], 1);
		i++;
	}
	fflush(stdout);
}
