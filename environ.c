#include "shell.h"

/**
 * environ - function to manipulate environment variables
 * @args: arguments passed in the commandline
 * @env: an array of environmenatal variables
 */
void environ(char **args, char **env)
{
	int i = 0;

	if (strcmp(args[0], "unsetenv") == 0)
	{
		if (args[1] == NULL)
		{
			printf("Usage: unsetenv VARIABLE\n");
			return;
		}
		else if (args[2] != NULL)
		{
			printf("Usage: unsetenv VARIABLE\n");
			return;
		}
		else
		{
			while (env[i] != NULL)
			{
				if (strncmp(args[1], env[i], strlen(args[1])) == 0 && env[i][strlen(args[1])] == '=')
				{
					while (env[i - 1] != NULL)
					{
						env[i] = env[i + 1];
						i++;
					}
					return;
				}
				i++;
			}
			printf("variable %s does not exist\n", args[1]);
			return;
		}
	}
}

