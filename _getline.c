#include "main.h"

/**
 * Here we will write _strtok
 */

/*eisras strtok */

/**
 * description here
 */

ssize_t _getline(char **lineptr, size_t *n)
{
	if (lineptr == NULL || n == NULL)
	{
		return (-1); /* Invalid argument */
	}

	static char buffer[READ_SIZE];
	static size_t buf_pos = 0;
	static ssize_t buf_size = 0;
	size_t i = 0, j;
	int x;

	while(1)
	{
		if (buf_pos == buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, READ_SIZE); /* buf is empty, read more charachters */
			if(buf_size <= 0)
			{
				return (i == 0 ? buf_size : i); /* -1 for error and 0 for eof */
			}
			buf_pos = 0;
		}

		x = buffer[buf_pos++];

		if(x == '\n' || x == EOF)
		{
			*lineptr = (char *)malloc(i + 1); /* allocate buffer for the line */
			if (lineptr == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			/* copy charchter allocated in buf */
			for (j = 0; j < i; j++)
			{
				(*lineptr)[j] = buffer[j];
			}

			(*lineptr)[i] = '\0'; /* null terminator to the string */
			return (i + 1); /* return num of char readed and new line also that's + 1*/
		}

		if (i >= *n - 1)
		{
			/* resize buf if needed*/
			*lineptr = (char *)realloc(*lineptr, *n * 2);
			if (*lineptr == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
			*n *= 2;
		}
		(lineptr)[i++];
	}
}
