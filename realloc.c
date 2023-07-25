#include "shell.h"

/**
 * _memset - fills memory with a given character or byte
 * @s: the pointer to the memory space
 * @b: the character to fill @s with
 * @n: the number of bytes to be filled
 *
 * Return: pointer to the memory space of @s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees characters of a given strings
 * @pp: given characters of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory space that has
 *		been deallocated
 * @ptr: pointer to previous allocated memory block
 * @old_size: size of the previous memory block
 * @new_size: size of the new memory block
 *
 * Return: pointer to the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)ptr)[old_size];
	free(ptr);

	return (new_ptr);
}
