#include "printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
/**
 * is_good - hi
 * @c: hi
 * Return: hi
 */
int is_good(char c)
{
	return (c == 'c' || c == 's' || c == '%' || c == 'd' || c == 'i');
}

/**
 * check - hi
 * @format : hi
 * Return: hi
 */
int check(const char *format)
{
	int i = 0;

	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (0);
		else if (format[i] == '%')
			i++;
		i++;
	}
	return (1);
}
/**
 * _printf - hi
 * @format: hi
 * @...: hi
 * Return: hi
 */
int _printf(const char *format, ...)
{
	va_list ls;
	int i = 0, ln = 0;

	va_start(ls, format);
	if (!check(format))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && is_good(format[i + 1]))
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(ls, int);

				write(1, &c, 1);
				ln++;
			}
			else if (format[i] == 's')
				ln += printstr(va_arg(ls, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				ln += pint(va_arg(ls, int));
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				ln++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			ln++;
		}
		i++;
	}
	va_end(ls);
	return (ln);
}
