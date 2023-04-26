#include "string.h"
/**
 * _strcpy - hi
 * Description
 * @s : hi
 * @ss : hi
 * Return: pointer
 */
char *_strcpy(char *s, char *ss)
{
	int i = 0, j = 0;

	while (1)
	{
		if (ss[j] == '\0')
		{
			s[i] = ss[j];
			break;
		}
		s[i++] = ss[j++];
	}
	return (s);
}
