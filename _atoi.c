#include "shell.h"

/**
 * interactive - Used to be returning (true)
 * if the shell is in interactive mode.
 * @info: Struct address.
 * Return: (1) means interactive mode,
 *  (0) otherwise.
 */
	int interactive(info_t *info)
{
		return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - Used to be checking if character is a delimeter.
 * @c: The (char) to be checked.
 * @delim: The delimeter string.
 * Return: (1) means true, (0) means false.
 */
	int is_delim(char c, char *delim)
{
		while (*delim)
			if (*delim++ == c)
				return (1);
		return (0);
}

/**
 * _isalpha - Used to be checking for alphabetic character.
 * @c: The character to input.
 * Return: (1) means c is alphabetic,
 *  (0) otherwise.
 */

	int _isalpha(int c)
{
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return (1);
		else
			return (0);
}

/**
 * _atoi - Used to be converting a string to an integer.
 * @s: The string to be converted.
 * Return: (0) means no numbers in string,
 *  (converted number) otherwise.
 */

	int _atoi(char *s)
{
		int z, the_sign = 1, flag = 0, output;
		unsigned int the_result = 0;

		for (z = 0; s[z] != '\0' && flag != 2; z++)
	{
			if (s[z] == '-')
				the_sign *= -1;

			if (s[z] >= '0' && s[z] <= '9')
		{
				flag = 1;
				the_result *= 10;
				the_result += (s[z] - '0');
		}
			else if (flag == 1)
				flag = 2;
	}

		if (the_sign == -1)
			output = -the_result;
		else
			output = the_result;

		return (output);
}
