#include "shell.h"

/**
 * list_len - Used to be determining the length of the linked list.
 * @h: A pointer to the first node.
 * Return: The (size) of the list.
 */
	size_t list_len(const list_t *h)
{
		size_t z = 0;

		while (h)
	{
			h = h->next;
			z++;
	}
		return (z);
}

/**
 * list_to_strings - Used to be returning array of strings of (list->str).
 * @head: A pointer to the first node.
 * Return: The (array) of strings.
 */
	char **list_to_strings(list_t *head)
{
		list_t *node = head;
		size_t z = list_len(head), j;
		char **strings;
		char *str;

		if (!head || !z)
			return (NULL);
		strings = malloc(sizeof(char *) * (z + 1));
		if (!strings)
			return (NULL);
		for (z = 0; node; node = node->next, z++)
	{
			str = malloc(_strlen(node->str) + 1);
			if (!str)
		{
				for (j = 0; j < z; j++)
					free(strings[j]);
				free(strings);
				return (NULL);
		}

			str = _strcpy(str, node->str);
			strings[z] = str;
	}
		strings[z] = NULL;
		return (strings);
}

/**
 * print_list - Used to be printing elements of list_t.
 * @h: A pointer to the first node.
 * Return: The (size) of list.
 */
	size_t print_list(const list_t *h)
{
		size_t z = 0;

		while (h)
	{
			_puts(convert_number(h->num, 10, 0));
			_putchar(':');
			_putchar(' ');
			_puts(h->str ? h->str : "(nil)");
			_puts("\n");
			h = h->next;
			z++;
	}
		return (z);
}

/**
 * node_starts_with - Used to be returning node string starts with prefix.
 * @node: A pointer to the list head.
 * @prefix: The string.
 * @c: The next character after prefix.
 * Return: (match) node or (null).
 */
	list_t *node_starts_with(list_t *node, char *prefix, char c)
{
		char *pointer = NULL;

		while (node)
	{
			pointer = starts_with(node->str, prefix);
			if (pointer && ((c == -1) || (*pointer == c)))
				return (node);
			node = node->next;
	}
		return (NULL);
}

/**
 * get_node_index - Used to be geting index of node.
 * @head: A pointer to the list head.
 * @node: A pointer to the node.
 * Return: (index) of node or (-1).
 */
	ssize_t get_node_index(list_t *head, list_t *node)
{
		size_t z = 0;

		while (head)
	{
			if (head == node)
				return (z);
			head = head->next;
			z++;
	}
		return (-1);
}
