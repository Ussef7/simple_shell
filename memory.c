#include "shell.h"

/**
 * bfree - frees a given pointer and empty its address
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if freed otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

