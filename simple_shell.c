#include "shell.h"
/**
 * main - hi
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: environmetn
 * Return: hi
 **/
int main(int argc, char **argv, char **env)
{
	int is_file = 0, is_pipe = !isatty(0), stts = 0, tmp;
	size_t SIZE = 1000;
	char *s = malloc(SIZE), **argv2, *cmd;

	while (1)
	{
		argv2 = malloc(sizeof(*argv2)), cmd = 0, argv2[0] = 0, (void)argc, (void)env;
		display_prompt(is_pipe);
		if (!get_input(&s, &SIZE, argv2))
			exit(stts);
		parse_input(s, &cmd, &argv2);
		if (!_strlen(s) || !cmd || !_strlen(cmd))
		{
			clean_args(argv2);
			continue;
		}
		is_file = find_file(&cmd, _getenv("PATH", environ));
		if (is_file == -1 || !_strcmp(cmd, "exit"))
		{
			clean_strs(s, cmd, 0);
			exit_shell(argv2, argv, stts);
		}
		else if(!_strcmp(cmd, "env"))
			printenv(environ);
		else if (!is_file)
		{
			print_not_found(argv[0], cmd);
			execve(cmd, argv2, environ);
			stts = 127;
		}
		else if (fork() != 0)
		{
			wait(&tmp);
			stts = WEXITSTATUS(tmp);
		}
		else
			execve(cmd, argv2, environ);
		clean_args(argv2);
		clean_strs(cmd, 0, 0);
	}
	return (0);
}
