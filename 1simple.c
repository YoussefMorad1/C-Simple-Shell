#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
void display_prompt();
void get_input(char **ptr, size_t* sz);
void parse_input(char *s, char **cmd, char ***argv);
void clean_strs(char *s1, char *s2, char *s3);
void clean_args(char **argv);
int push(char ***argv, char *s);
void print_args(char **s);
/**
 * main - hi
 *
 * Return: hi
 */
int main(int argc, char **argv, char **envp)
{
	size_t noChrs, SIZE = 100;
	char *s = malloc(SIZE);
	if (!s)
		exit(1);
	while(1)
	{
		int id;
		char **argv2 = malloc(1), *cmd = 0;

		if (id = fork()) 
		{
			int exSt;

			wait(&exSt);
			if (!exSt)
				continue;
			else
				break;
		}
		argv2[0] = 0;
		display_prompt();
		get_input(&s, &SIZE);
		parse_input(s, &cmd, &argv2);
//		printf("str: %s\n", s);
//		printf("cmd: %s\n", cmd);
//		print_args(argv2);
		if (!strlen(s))
			exit(0);
		if (execvpe(cmd, argv2, envp) == -1)
		{
			printf("%s: No such file or directory\n", argv[0]);
			exit(0);
		}
	}
}
void display_prompt()
{
	printf("$ ");
}
void get_input(char **ptr, size_t* sz)
{
	int noChrs = getline(ptr, sz, stdin);
	if (noChrs == -1){
		free(*ptr);
//		printf("\n");
		exit(1);
	}
	char *s = *ptr;
	if (s[strlen(s) - 1] == '\n')
		/* remove the '\n' from the end */
		s[strlen(s) - 1] = '\0';
}
void parse_input(char *s, char **ptrCmd, char ***ptrarg)
{
	int i = 0, frst = 1, j = 0;

	while (s[i])
	{
		while(s[i] == ' ') i++;
		char *tmp = malloc(1);
		tmp[0] = '\0';
		while (s[i] && s[i] != ' ')
		{
			tmp = realloc(tmp, strlen(tmp) + 1);
			char *x = malloc(2);
			x[0] = s[i];
			x[1] = '\0';
			if (!tmp)
			{
				clean_strs(tmp, *ptrCmd, s);
				clean_args(*ptrarg);
				exit(1);
			}
			strcat(tmp, x);
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
			*ptrCmd = malloc(strlen(tmp) + 1);
			frst = 0;
			if (!*ptrCmd)
			{
				clean_strs(tmp, *ptrCmd, s);
				clean_args(*ptrarg);
				exit(1);
			}
			strcpy(*ptrCmd, tmp);
		}
		free(tmp);
	//	print_args(*ptrarg);
	}
}
void clean_strs(char *s1, char *s2, char *s3)
{
	if (s1)	free(s1);
	if (s2) free(s2);
	if (s3) free(s3);
}
void clean_args(char **argv)
{
	int j = 0;
	while (argv[j])
		free(argv[j++]);
	free(argv);
}
void print_args(char **argv)
{
	printf("all areguments: \n");
	int i = 0;
	while (argv[i]){
		printf("%d: %s\n", i, argv[i]);
		i++;
	}
}
int push(char ***ptr, char *s)
{
	int i = 0;
	char **argv = *ptr;

	while (argv[i]) i++;
	char **tmp = malloc((i + 2) * (sizeof *tmp));
	if (!tmp) return (0);
	memmove(tmp, argv, (i + 1) * sizeof(*tmp));
/*
	printf("first\n");
	print_args(*ptr);
	printf("second\n");
	print_args(tmp);
*/	
	free(argv);
	argv = tmp;
	argv[i] = malloc(strlen(s) + 1);
	if (!argv[i]) return (0);
	strcpy(argv[i], s);
	argv[i + 1] = 0;
	(*ptr) = argv;
	return (1);
}
