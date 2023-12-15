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
 * _strncat - concatenates two strings where n number.
 * @dest: pointer to dest string.
 * @src: pointer to source string.
 * @n: n bytes to copy from src.
 * Return: pointer to dest.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t d_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[d_len + i] = src[i];
	dest[d_len + i] = '\0';

	return (dest);
}
