#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: string to concatenate to dest
 * Return: the dest pointer
 */
char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
