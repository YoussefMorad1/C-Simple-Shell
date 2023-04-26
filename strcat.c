#include "string.h"
/**
 * _strcat - hi
 * @s : hi
 * @ss : yo
 * Return: hi
*/
char *_strcat(char *s, char *ss)
{
	int i = 0, j;

	while (s[i] != '\0')
		++i;
	for (j = i; ss[j - i] != '\0'; ++j)
		s[j] = ss[j - i];
	s[j] = '\0';
	return (s);
}
