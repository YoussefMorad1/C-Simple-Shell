#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	{
		exit(1);	
	}
	while(1)
	{
		char *argv2[] = {0};
		char *cmd = 0;

		display_prompt();
		get_input(&s, &SIZE);
		parseInput(s, &cmd, argv2);
		execve(s, argv2, envp);

	}
}
void get_input(char **ptr, size_t* sz)
{
	int noChrs = getline(ptr, sz, stdin);
	if (noChrs == -1){
		free(*ptr);
		exit(1);
	}
	char *s = *ptr;
	s[strlen(s) - 1] = '\0';
}
void parse_input(char *s, char **ptrCmd, char *argv[])
{
	int i = 0, frst = 1, j = 0;
	char *&cmd = *ptrCmd;

	i = 0;
	while (s[i])
	{
		while(s[i] == ' ') i++;
		char *tmp;
		while (s[i] && s[i] != ' '){
			strcat(tmp, &s[i]);
			if (!tmp)
			{
				clean_strs(tmp, cmd, s);
				clean_args(argv);
				exit(1);
			}
			i++;
		}
		if (!push(argv, tmp))
		{
			clean_strs(tmp, cmd, s);
			clean_args(argv);
			exit(1);
		}
		if (frst)
		{
			strcpy(cmd, tmp);
			frst = 0;
			if (!cmd)
			{
				clean_strs(tmp, cmd, s);
				clean_args(argv);
				exit(1);
			}
		}
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
int push(char **argv, char *s)
{
	int i = 0;

	while (argv[i]) i++;
	strcpy(argv[i], s);
	if (!argv[i])
		return (0);
	return (1);
}
