#include "shell.h"

/**
 * _printf - emulates the builtin printf
 * @format: specifies the formart to be printed
 */
void _printf(const char *format, ...)
{
	int num;
	char *str, ch;
	va_list args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					str = va_arg(args, char*);
					while (*str)
					{
						_putchar(*str);
						str++;
					}
					break;
				case 'd':
					num = va_arg(args, int);
					print_integer(num);
					break;
				case 'c':
					ch = va_arg(args, int);
					_putchar(ch);
					break;
				default :
					break;
			}
		}
		_putchar(*format);
		format++;
	}
	va_end(args);
	return;
}

/**
 * print_integer - prints integers using putchar
 * @num: integer to be printed
 */
void print_integer(int num)
{
	char buffer[10];
	int length = 0, digit, i;

	if (num == 0)
	{
		putchar('0');
		return;
	}
		
	while (num != 0)
	{
		digit = num % 10;
		buffer[length] = '0' + digit;
		num /= 10;
		length++;
	}
	
	for (i = length - 1; i >= 0; i--)
		_putchar(buffer[i]);
}
