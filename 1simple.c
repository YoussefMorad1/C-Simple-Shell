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
		else if (!strcmp(cmd, "exit"))
		{
			exit_shell(argv2, argv);
			continue;
		}
		else if (!is_file)
		{
			printf("%s: No such file or directory\n", argv[0]);
			continue;
		}
		if (fork())
		{
			wait(0);
			continue;
		}
		if (!strlen(s))
			exit(0);
		execvpe(cmd, argv2, envp);
	}
}
