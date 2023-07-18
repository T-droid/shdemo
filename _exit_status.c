#include "shell.h"

/**
 * myexit - checks the exit status and exits the shell
 * @args: pointer to commandline arguments
 */
void myexit(char **args)
{
	if (args[2] != NULL)
	{
		printf("exit\n./shell: exit: too many arguments\n");
		return;
	}
	if (atoi(args[1]) >= 0 && atoi(args[1]) <= 127)
		exit(atoi(args[1]));
	else
	{
		printf("exit\n./shell: exit: %s: numeric argument required\n", args[1]);
		return;
	}
	if (args[1] == NULL)
		exit(0);
}
