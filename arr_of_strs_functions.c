#include "header.h"
/**
 * print_args - print all arguments of arr of strs
 *
 * @argv: the arr of strs
 */
void print_args(char **argv)
{
	printf("all areguments: \n");
	int i = 0;

	while (argv[i])
	{
		printf("%d: %s\n", i, argv[i]);
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
	int i = 0;
	char **argv = *ptr;

	while (argv[i])
		i++;
	char **tmp = malloc((i + 2) * (sizeof(*tmp)));

	if (!tmp)
		return (0);
	memmove(tmp, argv, (i + 1) * sizeof(*tmp));
	argv = tmp;
	argv[i] = malloc(strlen(s) + 1);
	if (!argv[i])
		return (0);
	strcpy(argv[i], s);
	argv[i + 1] = 0;
	(*ptr) = argv;
	return (1);
}
