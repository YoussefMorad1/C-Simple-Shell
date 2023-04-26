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
		exit(_stoi(argv[1]));
	else
	{
		printstr("logout\n");
		printstr(argv_main[0]);
		printstr(": exit: too many arguments\n");
	}
}
