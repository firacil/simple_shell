#include "main.h"

/*eisras strtok */

/**
  * _getline - reads an entire line from shell
  * @lineptr: pointer to array of pointerstoring the address
  * of the buffer containing the text
  * @n: the size
  *
  * Return: return the number of characters read
  */
ssize_t _getline(char **lineptr, size_t *n)
{
	static char buffer[READ_SIZE];
	static ssize_t buf_pos;
	static ssize_t buf_size, k;
	size_t i = 0, j;
	int x;
	char *tmp = NULL;

	if (lineptr == NULL || n == NULL)
		return (-1); /* Invalid argument */

	while (1)
	{
		if (buf_pos == buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, READ_SIZE);
			if (buf_size <= 0)
				return (k == 0 ? buf_size : k);
			buf_pos = 0;
		}
		x = buffer[buf_pos++];
		if (x == '\n' || x == EOF)
		{
			*lineptr = (char *)malloc(i + 1); /* allocate buffer for the line */
			if (lineptr == NULL)
				perror("malloc"), exit(EXIT_FAILURE);
			for (j = 0; j < i; j++)
				(*lineptr)[j] = buffer[j];

			(*lineptr)[i] = '\0'; /* null terminator to the string */
			return (i + 1); /* return num of char readed and new line also that's + 1*/
		}
		if (i >= *n - 1)
		{
			*lineptr = (char *)realloc(*lineptr, *n * 2);
			if (*lineptr == NULL)
				perror("realloc"), exit(EXIT_FAILURE);
			*n *= 2;
		}
		(lineptr)[i++] = tmp;
	}
}
