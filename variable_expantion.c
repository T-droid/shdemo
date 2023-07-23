#include "shell.h"

/**
 * varexpand - expands variables
 * @args: commandline arguments
 */
void varexpand(char **args, int *status)
{
	int k, i, j;
	char buff[64];

	i = 1;
	while (args[i] != NULL)
	{
		j = 0;
		while (args[i][j] != '\0')
		{
			if (args[i][j] == '$')
			{
				j++;
				if (args[i][j] == '?')
				{
					printf("%d", *status);
					j++;
				}
				else if (args[i][j] == '$')
				{
					printf("%d", getpid());
					j++;
				}
				else
				{
					k = 0;
					while (args[i][j] != '\0' && (!(args[i][j] >= '!' && args[i][j] <= '/')))
					{
						buff[k] = args[i][j];
						j++;
						k++;
					}
					buff[k] = '\0';
					printf("%s", getenv(buff));
				}
			}			
			else if (args[i][j] == '#')
			{
				putchar('\n');
				return;
			}
			putchar(args[i][j]);
			if (args[i][j] != '\0')
				j++;
		}
		i++;
		putchar(' ');
	}
	putchar('\n');
	return;
}
