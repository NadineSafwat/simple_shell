#include "shell.h"

/**
 * builtinhdl - handles the builtin commands
 * @data: the data structure
 *
 * Return: 0 on success
 */
int builtinhdl(shell_t *data)
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
			return ((blt + i)->f(data));
		i++; }
	return (-1); }

/**
 * proexit - exits the program
 * @data: the data structure
 * Return: 0 on success
 */

int proexit(shell_t *data __attribute__((unused)))
{
	int code, i = 0;

	if (data->args[1] == NULL)
	{
		datafree(data);
		exit(errno);
	}
	while (data->args[1][i])
	{
		if (_isalpha(data->args[1][i++]) < 0)
		{
			data->error_msg = _strdup("Illegal number\n");
			return (-1);
		}
	}
		code = _atoi(data->args[1]);
		datafree(data);
		exit(code);
}

#define SETOWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * dirchan - changes the directory
 * @data: the data structure
 * Return: 1 on success and -1 on failure
 */
int dirchan(shell_t *data)
{
	char *home;

	home = _getenv("HOME");
	if (data->args[1] == NULL)
	{
		SETOWD(data->oldpwd);
		if (chdir(home) < 0)
			return (-1);
	}
	if (_strcmp(data->args[1], "-") == 0)
	{
		if (data->oldpwd == 0)
		{
			SETOWD(data->oldpwd);
			if (chdir(home) < 0)
				return (-1);
		}
		else
		{
			SETOWD(data->oldpwd);
			if (chdir(data->oldpwd) < 0)
				return (-1);
		}
	}
	else
	{	SETOWD(data->oldpwd);
		if (chdir(data->args[1]) < 0)
			return (-1);
	}
	return (1);
}
#undef GETCWD
