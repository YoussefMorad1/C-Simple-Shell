#include "shell.h"
/**
 * display_prompt - hi
 * @is_pipe: hi
 */
void display_prompt(int is_pipe)
{
	if (is_pipe)
		return;
	printstr("# ");
}
/**
 * get_input - get shell input
 * @ptr: pointer to string to get input in
 * @sz: pointer to size of the string
 * @argv: args to delete
 * Return: int
 */
int get_input(char **ptr, size_t *sz, char **argv)
{
	int noChrs = getline(ptr, sz, stdin);
	char *s;

	if (noChrs == -1)
	{
		if (*ptr)
			free(*ptr);
		clean_args(argv);
/*		printstr("\n");*/
		return (0);
	}
	s = *ptr;
	if (s[_strlen(s) - 1] == '\n')
		/* remove the '\n' from the end */
		s[_strlen(s) - 1] = '\0';
	return (1);
}
/**
 * parse_input - parse line of input to command and parameters
 * @s: string ipnut
 * @ptrCmd: pointer to string of command
 * @ptrarg: pointer to arr of strings of arguments
 */
void parse_input(char *s, char **ptrCmd, char ***ptrarg)
{
	int i = 0, frst = 1;
	char *tmp, *x, *tmp2;

	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!s[i])
			break;
		tmp = malloc(1), tmp[0] = 0;
		while (s[i] && s[i] != ' ')
		{
			tmp2 = malloc(_strlen(tmp) + 2);
			_strcpy(tmp2, tmp);
			free(tmp);
			tmp = tmp2;
			x = malloc(2), x[0] = s[i], x[1] = 0;
			if (!tmp)
			{
				clean_strs(tmp, *ptrCmd, s);
				clean_args(*ptrarg);
				exit(1);
			}
			_strcat(tmp, x);
			i++;
			free(x);
		}
		if (!push(ptrarg, tmp))
		{
			clean_strs(tmp, *ptrCmd, s);
			clean_args(*ptrarg);
			exit(1);
		}
		if (frst)
		{
			fill_command(ptrCmd, tmp, s, *ptrarg);
			frst = 0;
		}
		free(tmp);
	}
}
/**
 * fill_command - fill the command with str
 * @ptrCmd: pointer to command string
 * @s: string to be put in cmd
 * @mnStr: main line of input str (might get freed)
 * @ptrarg: pointer to array of arguments (might get freed)
 */
void fill_command(char **ptrCmd, char *s, char *mnStr, char **ptrarg)
{
	*ptrCmd = malloc(_strlen(s) + 1);
	if (!*ptrCmd)
	{
		clean_strs(s, *ptrCmd, mnStr);
		clean_args(ptrarg);
		exit(1);
	}
	_strcpy(*ptrCmd, s);
}
