#include "shell.h"

/**
 * _getline - reads aline from stream
 * @line: pointer to store the read line
 * @len: pointer to the length of the line
 * @file: stream
 * Return: number of bytes read
 */
ssize_t _getline(char **line, size_t *len, FILE *file)
{
	int ch = 0;
	size_t pos = 0, new_len;
	char *temp = NULL;

	if (*line == NULL)
	{
		*len = 10;
		*line = malloc(*len);
		if (*line == NULL)
			return (-1);
	}
	else
		*len = 10;

	while (ch  != '\n')
	{
		ch = fgetc(file);
		(*line)[pos++] = ch;
		if (pos >= *len)
		{
			new_len = 2 * (*len);
			if (new_len < *len)
				return (-1);
			*len = new_len;

			temp = realloc(*line, *len);
			if (temp == NULL)
				return (-1);
			*line = temp;
		}
	}
	if (*line[0] == '\n')
		return (1);
	(*line)[pos] = '\0';

	if (ch == EOF && pos == 0)
		return (-1);
	return (pos);
}
