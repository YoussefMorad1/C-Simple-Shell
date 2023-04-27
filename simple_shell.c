#include "shell.h"
/**
 *  * main - hi
 *   *
 *    * @argc: number of arguments
 *     * @argv: array of arguments
 *      * Return: hi
 *       */
int main(int argc, char **argv, char **env)
{
	int is_file = 0, is_pipe = !isatty(0);
	size_t SIZE = 1000;
	char *s = malloc(SIZE), **argv2, *cmd;

	(void)argc;
	errno = 0;
	while (1)
	{
		argv2 = malloc(sizeof(*argv2)), cmd = NULL, argv2[0] = 0;
		if (!is_pipe)
			display_prompt();
		if (!get_input(&s, &SIZE, argv2))
			exit(errno);
		parse_input(s, &cmd, &argv2);
		if (!_strlen(s) || !cmd || !_strlen(cmd))
		{
			clean_args(argv2);
			continue;
		}
		is_file = find_file(&cmd, _getenv("PATH"));
		if (is_file == -1 || !_strcmp(cmd, "exit"))
		{
			clean_strs(s, cmd, 0);
			if (is_file != -1)
				exit_shell(argv2, argv, errno);
			clean_args(argv2);
			exit(errno);
		}
		else if (!is_file)
		{
			printstr(argv[0]);
			printstr(": No such file or directory\n");
			execve(cmd, argv2, env);
		}
		else if (fork())
		{
			wait(0);
		}
		else
		{
			execve(cmd, argv2, env);
		}
		clean_args(argv2);
		clean_strs(cmd, 0, 0);
	}
	return (0);
}
