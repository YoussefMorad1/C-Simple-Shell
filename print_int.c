#include "printf.h"
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
/**
 * pint - hi
 * @x : hi
 * Return: hi
 */
int printint(int x)
{
	char *s;
	int y = x, ln = 0, m = 0, j = 0;
	int z;

	if (x < 0)
	{
		char c = '-';

		write(1, &c, 1);
		j = 1;
	}
	z = x;
	if (!x)
	{
		char c = '0';

		write(1, &c, 1);
		return (1);
	}
	while (y)
	{
		y /= 10;
		ln++;
	}
	s = malloc(ln + 1);
	if (!s)
		exit(1);
	s[ln] = '\0';
	ln--;
	while (z)
	{
		s[ln] = '0' + (z % 10) * (z < 0 ? -1 : 1);
		ln--;
		z /= 10;
	}
	m = printstr(s);
	free(s);
	return (m + j);
}
