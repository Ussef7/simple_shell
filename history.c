#include "shell.h"

/**
 * get_history_file - Used to be geting history file.
 * @info: The parameter struct.
 * Return: The string that is allocated containg history file.
 */
	char *get_history_file(info_t *info)
{
		char *buf, *dir;

		dir = _getenv(info, "HOME=");
		if (!dir)
			return (NULL);
		buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
		if (!buf)
			return (NULL);
		buf[0] = 0;
		_strcpy(buf, dir);
		_strcat(buf, "/");
		_strcat(buf, HIST_FILE);
		return (buf);
}

/**
 * write_history - Used to be creating a file,
 * or to be appending to existing file.
 * @info: The parameter struct.
 * Return: (1)- means success, otherwize (-1).
 */
	int write_history(info_t *info)
{
		ssize_t fd;
		char *_file_name = get_history_file(info);
		list_t *node = NULL;

		if (!_file_name)
			return (-1);

		fd = open(_file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
		free(_file_name);
		if (fd == -1)
			return (-1);
		for (node = info->history; node; node = node->next)
	{
			_putsfd(node->str, fd);
			_putfd('\n', fd);
	}
		_putfd(BUF_FLUSH, fd);
		close(fd);
		return (1);
}

/**
 * read_history - Used to be reading history from a file.
 * @info: The parameter struct.
 * Return: (histcount) means success, otherwise (0).
 */
	int read_history(info_t *info)
{
		int z, _last_ = 0, linecount = 0;
		ssize_t fd, rdlen, fsize = 0;
		struct stat st;
		char *buf = NULL, *_file_name = get_history_file(info);

		if (!_file_name)
			return (0);

		fd = open(_file_name, O_RDONLY);
		free(_file_name);
		if (fd == -1)
			return (0);
		if (!fstat(fd, &st))
			fsize = st.st_size;
		if (fsize < 2)
			return (0);
		buf = malloc(sizeof(char) * (fsize + 1));
		if (!buf)
			return (0);
		rdlen = read(fd, buf, fsize);
		buf[fsize] = 0;
		if (rdlen <= 0)
			return (free(buf), 0);
		close(fd);
		for (z = 0; z < fsize; z++)
			if (buf[z] == '\n')
		{
				buf[z] = 0;
				build_history_list(info, buf + _last_, linecount++);
				_last_ = z + 1;
		}
		if (_last_ != z)
			build_history_list(info, buf + _last_, linecount++);
		free(buf);
		info->histcount = linecount;
		while (info->histcount-- >= HIST_MAX)
			delete_node_at_index(&(info->history), 0);
		renumber_history(info);
		return (info->histcount);
}

/**
 * build_history_list - Used to be adding entry to history linked list.
 * @info: The structure containing potential arguments, Used to maintaining,
 * @buf: The buffer.
 * @linecount: The history linecount| histcount.
 * Return: Always (0).
 */
	int build_history_list(info_t *info, char *buf, int linecount)
{
		list_t *node = NULL;

		if (info->history)
			node = info->history;
		add_node_end(&node, buf, linecount);

		if (!info->history)
			info->history = node;
		return (0);
}

/**
 * renumber_history - Used to be renumbering history linked list
 * after every changes.
 * @info: The tructure containing potential arguments, Used to maintaining,
 * Return: New (histcount).
 */
	int renumber_history(info_t *info)
{
		list_t *node = info->history;
		int z = 0;

		while (node)
	{
			node->num = z++;
			node = node->next;
	}
		return (info->histcount = z);
}
