#include <unistd.h>

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
void _puts(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}
