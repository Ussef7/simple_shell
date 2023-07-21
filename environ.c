#include "shell.h"

/**
 * _myenv - Used to be printing the current environment.
 * @info: The structure containing potential arguments. Used to maintaining
 *          constant function prototype.
 * Return: Always (0).
 */
	int _myenv(info_t *info)
{
		print_list_str(info->env);
		return (0);
}

/**
 * _getenv - Used to get the value from an environ variable.
 * @info: The structure containing potential arguments. Used to maintaining
 * @name: Envi Vari name.
 * Return: (Value).
 */
	char *_getenv(info_t *info, const char *name)
{
		list_t *node = info->env;
		char *pointer;

		while (node)
	{
			pointer = starts_with(node->str, name);
			if (pointer && *pointer)
				return (pointer);
			node = node->next;
	}
		return (NULL);
}

/**
 * _mysetenv - Used to be initializing a new environment variable,
 *             modify an existing one.
 * @info: The structure containing potential arguments. Used to maintaining
 *        constant function prototype.
 *  Return: Always (0).
 */
	int _mysetenv(info_t *info)
{
		if (info->argc != 3)
	{
			_eputs("Incorrect number of arguements\n");
			return (1);
	}
		if (_setenv(info, info->argv[1], info->argv[2]))
			return (0);
		return (1);
}

/**
 * _myunsetenv - Used to be removing an environment variable.
 * @info: The structure containing potential arguments. Used to maintaining
 *        constant function prototype.
 * Return: Always (0).
 */
	int _myunsetenv(info_t *info)
{
		int z;

		if (info->argc == 1)
	{
			_eputs("Too few arguements.\n");
			return (1);
	}
		for (z = 1; z <= info->argc; z++)
			_unsetenv(info, info->argv[z]);

		return (0);
}

/**
 * populate_env_list - Used to be populating linked env list.
 * @info: The structure containing potential arguments. Used to maintaining
 *          constant function prototype.
 * Return: Always (0).
 */
	int populate_env_list(info_t *info)
{
		list_t *node = NULL;
		size_t z;

		for (z = 0; environ[z]; z++)
			add_node_end(&node, environ[z], 0);
		info->env = node;
		return (0);
}
