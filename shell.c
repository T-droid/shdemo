#include "shell.h"



/**
 * main - entry point
 * @ac: argument count
 * @av: array of arguments
 * @envp: array of environmentall variables
 * Return: always 0
 */
int main(int ac, char **av, char **envp)
{
	char *line = NULL;
	int bt;
	size_t len = 0;

	if (ac == 3)
	{
		if (_strcmp(av[1], "simple_shell") == 0)
			execute_script(av[2], envp);
		else
		{
			printf("simple_shell [filename]\n");
			exit(EXIT_FAILURE);
		}
	}

	while (1)
	{
		putchar('$');
		putchar(' ');
		fflush(stdout);		

		bt = _getline(&line, &len, stdin);
		if (bt == -1)
		{
			perror("getline");
			continue;	
		}
		if (bt == 1)
		{

			continue;
		}


		execute_commands(line, envp);
	}
	free(line);
	return (0);
}
