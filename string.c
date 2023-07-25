#include "shell.h"

/**
 * _strlen - returns the length of the given string
 * @s: string to check its length
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int str_len = 0;

	if (!s)
		return (0);

	while (*s++)
		str_len++;
	return (str_len);
}

/**
 * _strcmp - performs logical comparison between two strings
 * @s1: first given string
 * @s2: second given string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with a given @haystack
 * @haystack: string to search @haystack
 * @needle: the substring to find
 *
 * Return: address of next char of haystack ortherwise NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two given strings
 * @dest: destination buffer string
 * @src: source buffer string
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

