#include "shell.h"

/**
 * _erratoi - Used to be converting a string to an integer.
 * @s: The string that is going to be converted.
 * Return: (0) means that no numbers in string, converted number otherwise
 *       (-1) means that error.
 */
	int _erratoi(char *s)
{
		int z = 0;
		unsigned long int the_result = 0;

		if (*s == '+')
			s++;
		for (z = 0;  s[z] != '\0'; z++)
	{
			if (s[z] >= '0' && s[z] <= '9')
		{
				the_result *= 10;
				the_result += (s[z] - '0');
				if (the_result > INT_MAX)
					return (-1);
		}
			else
				return (-1);
	}
		return (the_result);
}

/**
 * print_error - Used to be printing  an error message.
 * @info: The parameter and the return info struct.
 * @estr: The string containing a specified error type.
 * Return: (0) means that no numbers in string, converted number otherwise
 *        (-1) means that error.
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
 * print_d - The function that prints a decimal (integer) number (base 10).
 * @input: Input.
 * @fd: The file_descriptor to write to.
 * Return: Number of characters printed.
 */
	int print_d(int input, int fd)
{
		int (*__putchar)(char) = _putchar;
		int z, the_count = 0;
		unsigned int abs, current;

		if (fd == STDERR_FILENO)
			__putchar = _eputchar;
		if (input < 0)
	{
			abs = -input;
			__putchar('-');
			the_count++;
	}
		else
			abs = input;
		current = abs;
		for (z = 1000000000; z > 1; z /= 10)
	{
			if (abs / z)
		{
				__putchar('0' + current / z);
				the_count++;
		}
			current %= z;
	}
		__putchar('0' + current);
		the_count++;

		return (the_count);
}

/**
 * convert_number - The converter function.
 * @num: Number.
 * @base: Base.
 * @flags: The argument flags.
 * Return: (String).
 */
	char *convert_number(long int num, int base, int flags)
{
		static char *array;
		static char buffer[50];
		char the_sign = 0;
		char *pointer;
		unsigned long N = num;

		if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
			N = -num;
			the_sign = '-';

	}
		array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
		pointer = &buffer[49];
		*pointer = '\0';

		do	{
			*--pointer = array[N % base];
		N /= base;
	}	while (N != 0);

		if (the_sign)
			*--pointer = the_sign;
		return (pointer);
}

/**
 * remove_comments - A function That replaces first instance of '#' with '\0'.
 * @buf: The address of the string to be modified.
 * Return: Always (0).
 */
	void remove_comments(char *buf)
{
		int z;

		for (z = 0; buf[z] != '\0'; z++)
			if (buf[z] == '#' && (!z || buf[z - 1] == ' '))
		{
				buf[z] = '\0';
				break;
		}
}
