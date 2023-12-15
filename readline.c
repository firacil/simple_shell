#include "main.h"

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);

/**
 * _realloc - realloc a mem block using malloc and free.
 * @ptr: pointer to mem prev allocated.
 * @old: size of old space..
 * @new_size: new memory belock bytes.
 * Return: NULL / ptr.
 */
void *_realloc(void *ptr, unsigned int old, unsigned int new_size)
{
	void *mem;
	char *p_cp, *fill;
	unsigned int index;

	if (new_size == old)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	p_cp = ptr;
	mem = malloc(sizeof(*p_cp) * new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}
	fill = mem;

	for (index = 0; index < old && index < new_size; index++)
		fill[index] = *p_cp++;

	free(ptr);
	return (mem);
}

/**
 * assign_lineptr - reassign the lineptr variable for _getline.
 * @lineptr: a buffer to store an input string.
 * @n: the size of lineptr.
 * @buffer: string to assign to lineptr.
 * @b: size of buffer.
 */

void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * _getline - Reads input from a stream.
 * @lineptr: a buffer to store input.
 * @n: size of line ptr.
 * @stream: stram to read from.
 * Return: number of bytes read.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);

	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);

		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';

	assign_lineptr(lineptr, n, buffer, input);

	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
