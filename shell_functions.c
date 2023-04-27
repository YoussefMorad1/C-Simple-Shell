#include "shell.h"
/**
 * exit_shell - exit the shell
 * @argv: arguments to exit command
 * @argv_main: arguments of the main function (shell program)
 */
void exit_shell(char **argv, char **argv_main, int stts)
{
	int x, chk = 1, i;

	if (!argv[1])
	{
		clean_args(argv);
		exit(stts);
	}	
	else if (!argv[2])
	{
		for (i = 0; argv[1][i];++i)
			if (argv[1][i] < '0' || argv[1][i] > '9')
				chk = 0;
		if (!chk)
		{
			printers(argv_main[0]);
			printers(": 1: exit: Illegal number: ");
			printers(argv[1]);
			printers("\n");
			errno = 2;
			return;
		}
		x = _stoi(argv[1]);
		if (x < 0)
		{
			printers(argv_main[0]);
			printers(": exit: Illegal number: ");
			printer(x);
			printers("\n");
			errno = 2;
			return;
		}
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
