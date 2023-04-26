#include "header.h"
/**
 * clean_strs - free memory of 3 strings
 * @s1 : str1
 * @s2 : str2
 * @s3 : str3
 */
void clean_strs(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
}
/**
 * clean_args - clean array of strs
 * @argv : array of strs
 */
void clean_args(char **argv)
{
	int j = 0;
	
	if (!argv) return;
	while (argv[j])
	{
		free(argv[j]);
		j++;
	}
//	free(argv[j]);
	free(argv);
}
