#include "shell.h"

/**
 **_strncpy - Used to be copiying a string.
 *@dest: The destination string that is copied to.
 *@src: The source of the string.
 *@n: The number of characters to be copied.
 *Return: The connected string.
 */
	char *_strncpy(char *dest, char *src, int n)
{
		int z, k;
		char *s = dest;

		z = 0;
		while (src[z] != '\0' && z < n - 1)
	{
			dest[z] = src[z];
			z++;
	}
		if (z < n)
	{
			k = z;
			while (k < n)
		{
				dest[k] = '\0';
				k++;
		}
	}
		return (s);
}

/**
 **_strncat - Used to be connecting two strings.
 *@dest: First string.
 *@src: Second string.
 *@n: The number of bytes to be used.
 *Return: The connected string.
 */
	char *_strncat(char *dest, char *src, int n)
{
		int z, k;
		char *s = dest;

		z = 0;
		k = 0;
		while (dest[z] != '\0')
			z++;
		while (src[k] != '\0' && k < n)
	{
			dest[z] = src[k];
			z++;
			k++;
	}
		if (k < n)
			dest[z] = '\0';
		return (s);
}

/**
 **_strchr - Used to be locating a character in string.
 *@s: The string to be parsed.
 *@c: The character that is going to look for.
 *Return: (s) a pointer to the memory area (s).
 */
	char *_strchr(char *s, char c)
{
		do {
			if (*s == c)
				return (s);
	}	while (*s++ != '\0');

		return (NULL);
}
