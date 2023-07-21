#include "shell.h"

/**
 * _myhistory - Used to display the history list, one command by line,
 * preceded with line numbers, starting at (0).
 * @info: The structure containing potential arguments. Used to be maintaining
 *        constant function prototype.
 *  Return: Always (0).
 */
	int _myhistory(info_t *info)
{
		print_list(info->history);
		return (0);
}

/**
 * unset_alias - Used to be seting  alias to a string.
 * @info: The parameter struct.
 * @str: The string (alias).
 * Return: Always (0) means that  success, (1) means an error.
 */
	int unset_alias(info_t *info, char *str)
{
		char *pointer, t;
		int _RET;

		pointer = _strchr(str, '=');
		if (!pointer)
			return (1);
		t = *pointer;
		*pointer = 0;
		_RET = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
		*pointer = t;
		return (_RET);
}

/**
 * set_alias - Used to be seting a alias to a string.
 * @info: The parameter struct.
 * @str: The string (alias).
 * Return: Always (0) means that success, (1) means an error
 */
	int set_alias(info_t *info, char *str)
{
		char *pointer;

		pointer = _strchr(str, '=');
		if (!pointer)
			return (1);
		if (!*++pointer)
			return (unset_alias(info, str));

		unset_alias(info, str);
		return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Used to be printing an alias string.
 * @node: The alias node.
 * Return: Always (0) means that success, (1) means an error.
 */
	int print_alias(list_t *node)
{
		char *pointer = NULL, *a = NULL;

		if (node)
	{
			pointer = _strchr(node->str, '=');
			for (a = node->str; a <= pointer; a++)
			_putchar(*a);
			_putchar('\'');
			_puts(pointer + 1);
			_puts("'\n");
			return (0);
	}
		return (1);
}

/**
 * _myalias - the alias builtin.
 * @info: The structure containing potential arguments. Used to maintaining.
 *          constant function prototype.
 *  Return: Always (0).
 */
	int _myalias(info_t *info)
{
		int z = 0;
		char *pointer = NULL;
		list_t *node = NULL;

		if (info->argc == 1)
	{
			node = info->alias;
			while (node)
		{
				print_alias(node);
				node = node->next;
		}
			return (0);
	}
		for (z = 1; info->argv[z]; z++)
	{
			pointer = _strchr(info->argv[z], '=');
			if (pointer)
				set_alias(info, info->argv[z]);
			else
				print_alias(node_starts_with(info->alias, info->argv[z], '='));
	}

		return (0);
}
