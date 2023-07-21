#include "shell.h"

/**
 * _eputs -Used to be  printing an input string.
 * @str: the string that is going to be printed.
 * Return: (Nothing).
 */
	void _eputs(char *str)
{
		int z = 0;

		if (!str)
			return;
		while (str[z] != '\0')
	{
			_eputchar(str[z]);
			z++;
	}
}

/**
 * _eputchar - Used to be writing character (c) to stderr.
 * @c: The character that is going to be printed.
 * Return: (1) means success.
 * On error, (-1) is returned, errno is set appropriately.
 */
	int _eputchar(char c)
{
		static int z;
		static char buf[WRITE_BUF_SIZE];

		if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
			write(2, buf, z);
			z = 0;
	}
		if (c != BUF_FLUSH)
			buf[z++] = c;
		return (1);
}

/**
 * _putfd - Used to be writing the character (c) to (fd).
 * @c: The character that is going to be printed.
 * @fd: The file_descriptor to write to.
 * Return: (1) means success.
 * On error, (-1) is returned, errno is set appropriately.
 */
	int _putfd(char c, int fd)
{
		static int z;
		static char buf[WRITE_BUF_SIZE];

		if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
			write(fd, buf, z);
			z = 0;
	}
		if (c != BUF_FLUSH)
			buf[z++] = c;
		return (1);
}

/**
 * _putsfd - Used to be printing an input string.
 * @str: The string that is going to be printed.
 * @fd: The file_descriptor to write to.
 * Return: Number of chars.
 */
	int _putsfd(char *str, int fd)
{
		int z = 0;

		if (!str)
			return (0);
		while (*str)
	{
			z += _putfd(*str++, fd);
	}
		return (z);
}
