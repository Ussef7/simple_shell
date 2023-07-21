#include "shell.h"

/**
 * get_environ - Used to be returning string array copy of environ.
 * @info: The structure containing potential arguments, Used to be maintaining,
 *          constant function prototype.
 * Return: Always (0).
 */
	char **get_environ(info_t *info)
{
		if (!info->environ || info->env_changed)
	{
			info->environ = list_to_strings(info->env);
			info->env_changed = 0;
	}

		return (info->environ);
}

/**
 * _unsetenv - Used to be removing environment var.
 * @info: The structure containing potential arguments. Used to be maintaining,
 *        constant function prototype.
 *  Return: (1)- means delete, (0)- otherwise.
 * @var: The string environ vari.
 */
	int _unsetenv(info_t *info, char *var)
{
		list_t *node = info->env;
		size_t z = 0;
		char *pointer;

		if (!node || !var)
			return (0);

		while (node)
	{
			pointer = starts_with(node->str, var);
			if (pointer && *pointer == '=')
		{
				info->env_changed = delete_node_at_index(&(info->env), z);
				z = 0;
				node = info->env;
				continue;
		}
			node = node->next;
			z++;
	}
		return (info->env_changed);
}

/**
 * _setenv - Used to be initializing a new environment variable,
 *             or modify an existing environment variable.
 * @info: The structure containing potential arguments, Used to be maintaining,
 *        constant function prototype.
 * @var: The string envron vari.
 * @value: The string envron vari (value).
 *  Return: Always (0).
 */
	int _setenv(info_t *info, char *var, char *value)
{
		char *buf = NULL;
		list_t *node;
		char *pointer;

		if (!var || !value)
			return (0);

		buf = malloc(_strlen(var) + _strlen(value) + 2);
		if (!buf)
			return (1);
		_strcpy(buf, var);
		_strcat(buf, "=");
		_strcat(buf, value);
		node = info->env;
		while (node)
	{
			pointer = starts_with(node->str, var);
			if (pointer && *pointer == '=')
		{
				free(node->str);
				node->str = buf;
				info->env_changed = 1;
				return (0);
		}
			node = node->next;
	}
		add_node_end(&(info->env), buf, 0);
		free(buf);
		info->env_changed = 1;
		return (0);
}
