#include "shell.h"

/**
 * findpath - comand to handle the path
 * @str: command
 * Return: path to the command or NULL
 */
char *findpath(char *str)
{
	char *path = strdup(getenv("PATH"));
	char *token, *path2[1024], *ptr;
	int i = 0;

	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");
	while (token != NULL && i < 1024)
	{
		path2[i] = token;
		i++;
		token = strtok(NULL, ":");
	}
	path2[i] = NULL;

	i = 0;
	while (path2[i] != NULL)
	{
		ptr = malloc(_strlen(path2[i]) + _strlen(str) + 1);
		if (ptr == NULL)
		{
			perror("malloc");
			free(path);
			return (NULL);
		}

		_strcpy(ptr, path2[i]);
		_strcat(ptr, "/");
		_strcat(ptr, str);
		if (access(ptr, F_OK) == 0)
		{
			free(path);
			return (ptr);
		}
		free(ptr);
		i++;
	}
	free(path);
	return (NULL);
}
