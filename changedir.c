#include "shell.h"

/**
 * changedir - function to facilitate directory navigaation
 * @args: arguments passed to the commandline
 * Return: 1 if error and 0 on succes
 */
int changedir(char **args)
{
	char buff[4096];
	char *path;

	if (args[1] == NULL)
	{
		path = getenv("HOME");
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (args[2] != NULL)
		{
			printf("./shell: cd: too many arguments\n");
			return (1);
		}
		path = getenv("OLDPWD");
		if (path == NULL)
		{
			printf("./shell: cd: OLDPWD not set\n");
			return (1);
		}
	}
	else
	{
		if (args[2] != NULL)
		{
			printf("./shell: cd: too many arguments\n");
			return (1);
		}
		path = args[1];
	}
	if (getcwd(buff, sizeof(buff)) == NULL)
	{
			perror("getcwd error");
			return (1);
	}
	if (chdir(path) != 0)
	{
		printf("./shell: cd: %s: No such file or directory\n", path);
		return (1);
	}
	else
	{
		setenv("OLPWD", buff, 1);
		if (getcwd(buff, sizeof(buff)) == NULL)
		{
			perror("getcwd error");
		}
		setenv("PWD", buff, 1);
	}
	return (0);
}
