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
	if (!s)
		exit(1);
	while (1)
	{
		char **argv2 = malloc(1), *cmd = 0;
		int is_file = 0;

		argv2[0] = 0;
		display_prompt();
		get_input(&s, &SIZE);
		parse_input(s, &cmd, &argv2);
		is_file = find_file(cmd, getenv("PATH"));
		if (is_file == -1)
		{
			clean_strs(s, cmd, 0);
			clean_args(argv2);
			exit(1);
		}
		else if (!_strcmp(cmd, "exit"))
			exit_shell(argv2, argv);
		else if (!is_file)
			_printf("%s: No such file or directory\n", argv[0]);
		else if (fork())
			wait(0);
		else if (!_strlen(s))
			exit(0);
		else
			execve(cmd, argv2, envp);
		clean_args(argv2);
		clean_strs(cmd, 0, 0);
	}
	return (0);
}
