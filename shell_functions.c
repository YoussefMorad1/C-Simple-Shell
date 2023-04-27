#include "shell.h"
/**
 * exit_shell - exit the shell
 * @argv: arguments to exit command
 * @argv_main: arguments of the main function (shell program)
 */
void exit_shell(char **argv, char **argv_main, int stts)
{
	int x;

	if (!argv[1])
	{
		clean_args(argv);
		exit(stts);
	}
	else if (argv[1] && !argv[2])
	{
		x = _stoi(argv[1]);
		clean_args(argv);
		exit(x);
	}
	else
	{
		printstr("logout\n");
		printstr(argv_main[0]);
		printstr(": exit: too many arguments\n");
	}
}
