#include "shell.h"

/**
 * parser - determines commandline arguments
 * @str: array of commandline arguments
 * @staus: keeps track of the exit status
 * Return: 0 if succesfull or -1 if otherwise
 */
int parser(char **str, char **env, int *status)
{
	if (strcmp(str[0], "exit") == 0)
	{
		myexit(str);
		*status = 1;
		return (0);
	}
	if (strcmp(str[0], "unsetenv") == 0 || strcmp(str[0], "setenv") == 0)
	{
		*status = environ(str, env);
		return (0);
	}
	if (strcmp(str[0], "cd") == 0)
	{
		*status = changedir(str);
		return (0);
	}
	if (strcmp(str[0], "echo") == 0)
	{
		varexpand(str, status);
		*status = 0;
		return (0);
	}
	return (-1);
}
