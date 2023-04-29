#include "shell.h"
/**
 * print_args - print all arguments of arr of strs
 *
 * @argv: the arr of strs
 */
void print_args(char **argv)
{
	int i = 0;

	printstr("all areguments: \n");
	while (argv[i])
	{
		printint(i);
		printstr(": ");
		printstr(argv[i]);
		printstr("\n");
		i++;
	}
}
/**
 * push - pushes a string back to arr of strs
 *
 * @ptr: pointer to the arr
 * @s: the string
 *
 * Return: 1 or 0
 */
int push(char ***ptr, char *s)
{
	int i = 0, j;
	char **argv = *ptr, **tmp, **oldptr;

	while (argv[i])
		i++;
	tmp = malloc((i + 2) * (sizeof(*tmp)));
	if (!tmp)
		return (0);
	for (j = 0; j <= i; j++)
		tmp[j] = argv[j];
	oldptr = argv;
	argv = tmp;
	argv[i] = malloc(_strlen(s) + 1);
	if (!argv[i])
		return (0);
	_strcpy(argv[i], s);
	argv[i + 1] = 0;
	(*ptr) = argv;
	free(oldptr);
	return (1);
}
