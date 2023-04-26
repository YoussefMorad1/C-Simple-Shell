#include "header.h"
/**
 * main - hi
 *
 * @argc: number of arguments
 * @argv: array of arguments
 * @envp: array of enviroment variables
 * Return: hi
 */
int main(int argc, char **argv)
{
	size_t SIZE = 100;
	char *s = malloc(SIZE);

	(void)argc;
	if (!s)
		exit(1);
	while (1)
	{
		char **argv2 = malloc(sizeof(*argv2)), *cmd = NULL;
		int is_file = 0;

		argv2[0] = NULL;
		display_prompt();
		get_input(&s, &SIZE, argv2);
		if (!_strlen(s))
		{
			clean_args(argv2);
			continue;
		}
		parse_input(s, &cmd, &argv2);
		is_file = find_file(&cmd, _getenv("PATH"));
		if (is_file == -1 || !_strcmp(cmd, "exit"))
		{
			if (is_file == -1)
			{
				clean_args(argv2);
				exit(1);
			}
			clean_strs(s, cmd, 0);
			exit_shell(argv2, argv);
		}
		else if (!is_file)
		{
			printstr(argv[0]);
			printstr(": No such file or directory\n");
		}
		else if (fork())
			wait(0);
		else
			execve(cmd, argv2, environ);
		clean_args(argv2);
		clean_strs(cmd, 0, 0);
	}
	return (0);
}
