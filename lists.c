#include "shell.h"

/**
 * add_node - Used to be adding node to the start of list.
 * @head: The address of pointer to be heading a node.
 * @str: (str) field of node.
 * @num: Node index that is used by the history.
 * Return: The size of the list.
 */
	list_t *add_node(list_t **head, const char *str, int num)
{
		list_t *new_head;

		if (!head)
			return (NULL);
		new_head = malloc(sizeof(list_t));
		if (!new_head)
			return (NULL);
		_memset((void *)new_head, 0, sizeof(list_t));
		new_head->num = num;
		if (str)
	{
			new_head->str = _strdup(str);
			if (!new_head->str)
		{
				free(new_head);
				return (NULL);
		}
	}
		new_head->next = *head;
		*head = new_head;
		return (new_head);
}

/**
 * add_node_end - Used to be adding node to the end of list.
 * @head: The address of pointer to be heading a node.
 * @str: (str) field of node.
 * @num: Node index that is used by the history.
 * Return: The size of the list.
 */
	list_t *add_node_end(list_t **head, const char *str, int num)
{
		list_t *new_node, *node;

		if (!head)
			return (NULL);

		node = *head;
		new_node = malloc(sizeof(list_t));
		if (!new_node)
			return (NULL);
		_memset((void *)new_node, 0, sizeof(list_t));
		new_node->num = num;
		if (str)
	{
			new_node->str = _strdup(str);
			if (!new_node->str)
		{
				free(new_node);
				return (NULL);
		}
	}
		if (node)
	{
			while (node->next)
				node = node->next;
			node->next = new_node;
	}
		else
			*head = new_node;
		return (new_node);
}

/**
 * print_list_str - Used to be only printing,
 * str element of the linked list list_t.
 * @h: A pointer to The first node.
 * Return: The size of The list.
 */
	size_t print_list_str(const list_t *h)
{
		size_t z = 0;

		while (h)
	{
			_puts(h->str ? h->str : "(nil)");
			_puts("\n");
			h = h->next;
			z++;
	}
		return (z);
}

/**
 * delete_node_at_index - Used to be deleting a node at index that is given.
 * @head: The address of The pointer to the first node.
 * @index: The index of The node to be deleted.
 * Return: (1)-means (success), (0)-means (failure).
 */
	int delete_node_at_index(list_t **head, unsigned int index)
{
		list_t *node, *prev_node;
		unsigned int z = 0;

		if (!head || !*head)
			return (0);

		if (!index)
	{
			node = *head;
			*head = (*head)->next;
			free(node->str);
			free(node);
			return (1);
	}
		node = *head;
		while (node)
	{
			if (z == index)
		{
				prev_node->next = node->next;
				free(node->str);
				free(node);
				return (1);
		}
			z++;
			prev_node = node;
			node = node->next;
	}
		return (0);
}

/**
 * free_list - Used to be freing all nodes of a list.
 * @head_ptr: The address of the pointer to be heading node.
 * Return: (void).
 */
	void free_list(list_t **head_ptr)
{
		list_t *node, *next_node, *head;

		if (!head_ptr || !*head_ptr)
			return;
		head = *head_ptr;
		node = head;
		while (node)
	{
			next_node = node->next;
			free(node->str);
			free(node);
			node = next_node;
	}
		*head_ptr = NULL;
}
