#include "shell.h"


/**
 * environ - function to manipulate environment variables
 * @args: arguments passed in the commandline
 * @env: an array of environmenatal variables
 */
int environ(char **args, char **env)
{
	int i = 0;

	if (_strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
		{
			printf("Usage: unsetenv VARIABLE\n");
			return (1);
		}
		else if (args[2] != NULL)
		{
			printf("Usage: unsetenv VARIABLE\n");
			return (1);
		}
		else
		{
			while (env[i] != NULL)
			{
				if (_strncmp(args[1], env[i], _strlen(args[1])) == 0 && env[i][_strlen(args[1])] == '=')
				{
					while (env[i - 1] != NULL)
					{
						env[i] = env[i + 1];
						i++;
					}
					return (0);
				}
				i++;
			}
			printf("variable %s does not exist\n", args[1]);
			return (1);
		}
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		if (args[1] == NULL || args[2] == NULL)
		{
			printf("Usage: setenv VARIABLE VALUE\n");
			return (1);
		}
		else if (args[3] != NULL)
		{
			printf("Usage: setenv VARIABLE VALUE\n");
			return (1);
		}
		env_helper(args[1], args[2], env);
	}
	return (0);
}


/**
 * env_helper - helper function to setenv
 * @s1: first commandline argument
 * @s2: second commandline argument
 * @env: array of environmental variables
 */
void env_helper(char *s1, char *s2, char **env)
{
	int i = 0;
	char *epr;

	epr = malloc(_strlen(s1) + _strlen(s2) + 1);
	_strcpy(epr, s1);
	_strcat(epr, "=");
	_strcat(epr, s2);

	while (env[i] != NULL)
	{
		if (_strncmp(s1, env[i], _strlen(s1)) == 0 && env[i][_strlen(s1)] == '=')
		{
			env[i] = epr;
			return;
		}
		i++;
	}
	env[i] = epr;
	env[i + 1] = NULL;
	return;
}
