#include "shell.h"

/**
 * helpp - display the help menu
 * @data: the data structure
 *
 * Return: 1 on success or -1 on failure
 */
int helpp(shell_t *data)
{
	int fd, fw, rd = 1;
	char c;

	fd = open(data->args[1], O_RDONLY);
	if (fd < 0)
	{
		data->error_msg = _strdup("no help topics match\n");
		return (-1);
	}
	while (rd > 0)
	{
		rd = read(fd, &c, 1);
		fw = write(STDOUT_FILENO, &c, rd);
		if (fw < 0)
		{
			data->error_msg = _strdup("cannot write: permission denied\n");
			return (-1);
		}
	}
	PRINT("\n");
	return (1);
}
