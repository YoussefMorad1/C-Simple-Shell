#include "shell.h"
/**
 * main - hi
 *
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: hi
 */
int main(int argc, char **argv)
{
	int is_file = 0, is_pipe = !isatty(0), stts = 0;
	size_t SIZE = 1000;
	char *s = malloc(SIZE), **argv2, *cmd;

	(void)argc;
	while (1)
	{
		argv2 = malloc(sizeof(*argv2)), cmd = NULL, argv2[0] = 0;
		if (!is_pipe)
			display_prompt();
		if (!get_input(&s, &SIZE, argv2))
			exit(stts);
		parse_input(s, &cmd, &argv2);
		if (!_strlen(s) || !cmd || !_strlen(cmd))
		{
			clean_args(argv2);
			continue;
		}
		is_file = find_file(&cmd, _getenv("PATH"));
		if (is_file == -1 || !_strcmp(cmd, "exit"))
		{
			/*printint(stts);
			printstr("\n");
			printint(errno);
			printstr("\n");*/
			if (stts)
				stts = errno;
			clean_strs(s, cmd, 0);
			if (is_file != -1)
				exit_shell(argv2, argv, stts);
			stts = errno;
			clean_args(argv2);
			exit(stts);
		}
		else if (!is_file)
		{
			printers(argv[0]);
			printers(": No such file or directory\n");
			execve(cmd, argv2, environ);
			stts = errno;
		}
		else if (fork())
		{
			wait(&stts);
		}
		else
		{
			execve(cmd, argv2, environ);
			stts = errno;
		}
		clean_args(argv2);
		clean_strs(cmd, 0, 0);
	}
	return (0);
}
