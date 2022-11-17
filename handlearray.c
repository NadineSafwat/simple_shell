#include "shell.h"

/**
 * arrayf - fill an array with number
 * @ary: the array to filled with number
 * @num: the number to filled in
 * @len: array length
 * Return: nothing
 */

void *arrayf(void *ary, int num, unsigned int len)
{
	char *ptr = ary;
	unsigned int i;

	i = 0;

	while (i < len)
	{
		*ptr = num;
		ptr++;
		i++;
	}
	return (ary);
}



/**
 * _getenv - gets the path
 * @path_name: the name of the path
 * Return: nothing
 */

char *_getenv(char *path_name)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}



/**
 * reva - reverses array
 * @ary: given array
 * @len: array length
 * Return: nothing
 */

void reva(char *ary, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = ary[i];
		ary[i] = ary[(len - 1) - i];
		ary[(len - 1) - i] = tmp;
	}
}
