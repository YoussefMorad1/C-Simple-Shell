#include "header.h"
/**
 * exit_shell - exit the shell
 * @argv: arguments to exit command
 * @argv_main: arguments of the main function (shell program)
 */
void exit_shell(char **argv, char **argv_main)
{
	if (!argv[1])
		exit(0);
	else if (argv[1] && !argv[2])
		exit(atoi(argv[1]));
	else
	{
		printf("logout\n");
		printf("%s: %s: too many arguments\n", argv_main[0], "exit");
	}
}
