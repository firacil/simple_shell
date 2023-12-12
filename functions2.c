#include "main.h"


/**
 * _strcat - concatenate strings.
 * @dest: string to be concatenated.
 * @src: string to be concatenated to.
 * Return: orginal dest.
 */

char *_strcat(char *dest, const char *src)
{
	char *orginal = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (orginal);
}

/**
 * pr_digit - print digit recursively.
 * @n: number
 * Return: None.
 */

void pr_digit(int n)
{
	if (n == 0)
	{
		return;
	}

	pr_digit(n / 10);
	_putchar('0' + n % 10);
}

/**
 * printint - print intger.
 * @num: number.
 * Return: None.
 */

void printint(int num)
{
	/* handle negeative number */
	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	else if (num == 0)
	{
		_putchar('0');
	}
	else
	{
		pr_digit(num);
	}
}

/**
 * _echo - handle variables.
 * @argv: string passed.
 * Return: none
 */

void _echo(char **argv)
{
	int stat, pid;
	char *pvalue;

	if (_strcmp(argv[1], "$?") == 0)
	{
		stat = system("true");
		printint(stat);
		_putchar('\n');
	}
	else if (_strcmp(argv[1], "$$") == 0)
	{
		pid = getpid();
		printint(pid);
		_putchar('\n');
	}
	else if (_strcmp(argv[1], "$PATH") == 0)
	{
		pvalue = getenv("PATH");
		_puts(pvalue);
		_putchar('\n');
	}
	else
		return;
}
