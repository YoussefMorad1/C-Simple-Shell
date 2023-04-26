#include "shell.h"
#include <limits.h>

/**
 * _erratoi - converts string to integer
 * @s: string convert
 * Return: (0) if no numbers in string, converted number otherwise
 *       (-1) on error
 */

int _erratoi(char *s)

{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints error
 * @info: the parameter & return info struct
 * @estr: string containing specified error
 * Return: (0) if no numbers in string, converted number otherwise
 *        (-1) on error
 */

void print_error(info_t *info, char *estr)

{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints decimal (integer) number (base 10)
 * @input: the input
 * @fd: filedescriptor to write to
 *
 * Return: no of characters printed
 */

int print_d(int input, int fd)
{
	int (*__putchar)(char) = __putchar;
	int i, c = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = __putchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		c++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			c++;
		}
		current %= i;
	}
	__putchar('0' + current);
	c++;

	return (c);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: the number
 * @base: the basee
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)

{
	static char *array;
	static char buffer[50];
	char *ptr;
	char sign = 0;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - replaces first instance of '#' with '\0'
 * @buf: address of string to modify
 *
 * Return: Always 0;
 */

void remove_comments(char *buf)

{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
