#include "shell.h"

#define DELIMITER ":"
/**
 * lparse - parses the arguments
 * @data: the data structure
 *
 * Return: 0, 1 or -1
 */

int lparse(shell_t *data)
{
	if (filepath(data) > 0)
		return (1);
	if (built_in(data) > 0)
	{
		if (builtinhdl(data) < 0)
			return (-1);
		return (0);
	}
	shortfile(data);
	return (1);
}

/**
 * shortfile - check if the file name is shortened
 * @data: the data structure
 *
 * Return: nothing
 */

void shortfile(shell_t *data)
{
	char *path, *tokn, *_path;
	struct stat st;
	int exist_flag = 0;

	path = _getenv("PATH");
	_path = _strdup(path);
	tokn = strtok(_path, DELIMITER);
	while (tokn)
	{
		data->cmd = _strcat(tokn, data->args[0]);
		if (stat(data->cmd, &st) == 0)
		{
			exist_flag += 1;
			break;
		}
		free(data->cmd);
		tokn = strtok(NULL, DELIMITER);
	}
	if (exist_flag == 0)
	{
		data->cmd = _strdup(data->args[0]);
	}
	free(_path);
}
#undef DELIMITER

/**
 * filepath - checks if given file name is a path
 * @data: the data structure
 *
 * Return: 1 on sucess or -1 on failure
 */
int filepath(shell_t *data)
{
	if (_strchr(data->args[0], '/') != 0)
	{
		data->cmd = _strdup(data->args[0]);
			return (1);
	}
	return (-1);
}

/**
 * built_in - checks if the command is builtin
 * @data: the data structure
 *
 * Return: 0 or 1
 */

int built_in(shell_t *data)
{
	blt_t blt[] = {
		{"exit", proexit},
		{"cd", dirchan},
		{"help", helpp},
		{NULL, NULL}
	};

	int i = 0;

	while ((blt + i)->cmd)
	{
		if (_strcmp(data->args[0], (blt + i)->cmd) == 0)
			return (1);
		i++;
	}
	return (0);
}
