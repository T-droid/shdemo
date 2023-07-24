#include "shell.h"

/**
 * _strlen - returns length
 *
 * @s: parameter
 * Return: returns the length
 */
int _strlen(char *s)
{
	int i;
	int count = 0;

	if (s == NULL)
		return (-1);

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		count++;
	}
	return (count);
}

/**
 * char *_strcpy - copies array
 *
 * @dest: destination to be copied
 * @src:destination to copy
 * Return: returns value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == NULL)
		return (NULL);
	for (i = 0 ; src[i] != '\0' ; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strdup - creates a duplicate of a string
 * @str: the string to be duplicated
 * Return: pointe to the new string
 */
char *_strdup(char *str)
{
	int i = 0, count = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	ptr = (char *)malloc(sizeof(char) * count + 1);
	if (ptr == NULL)
		return (NULL);

	for (i = 0 ; i < count ; i++)
	{
		ptr[i] = str[i];
	}
	ptr[i] = '\0';

	return (ptr);
}

/**
 * _strncmp - compares n bytes of two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to be compared
 * Return: 0 if same and non-zero if otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
}

/**
 * _strcmp - compares two strings if they are the same
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if equal and non-zero if not
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}
