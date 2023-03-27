#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 *
 * @format: format string containing directives
 *		to indicate how to format output
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int chars_printed = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*(++format))
			{
				case 'd':
					chars_printed += printf("%d", va_arg(args, int));
					break;
				case 'c':
					chars_printed += printf("%c", va_arg(args, int));
					break;
				case 's':
					chars_printed += printf("%s", va_arg(args, char *));
					break;
				default:
					break;
			}
		}
		else
		{
			putchar(*format);
			chars_printed++;
		}

		format++;
	}

	va_end(args);

	return (chars_printed);
}

