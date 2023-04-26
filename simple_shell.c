#include "header.h"
/**
 * main - hi
 *
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array of enviroment variables
 * Return: hi
 */
int main(int argc, char **argv, char **envp)
{
	size_t SIZE = 100;
	char *s = malloc(SIZE);

	(void)argc;
	(void)argv;
	if (!s)
		exit(1);
	while (1)
	{
		char **argv2 = malloc(1), *cmd = 0;

		argv2[0] = 0;
		display_prompt();
		get_input(&s, &SIZE);
		if(fork())
		{
			wait(0);
			continue;
		}
		execve(s, argv2, envp);
		clean_args(argv2);
		clean_strs(cmd, 0, 0);
	}
	return (0);
}
