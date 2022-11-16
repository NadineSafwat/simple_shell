#include "shell.h"

/**
 * main - the program entry point
 *
 * Return: Always returns zero
 */
int main(void)
{
	shell_t data;
	int pline;

	_memset((void *)&data, 0, sizeof(data));
	signal(SIGINT, handlesig);
	while (1)
	{
		cmdId(&data);
		if (get_line(&data) < 0)
		{
			if (isatty(STDIN_FILENO))
				PRINT("\n");
			break;
		}
		if (linesplit(&data) < 0)
		{
			datafree(&data);
			continue;
		}
		pline = lparse(&data);
		if (pline == 0)
		{
			datafree(&data);
			continue;
		}
		if (pline < 0)
		{
			printerr(&data);
			continue;
		}
		if (cmdpro(&data) < 0)
		{
			printerr(&data);
			break;
		}
		datafree(&data);
	}
	datafree(&data);
	exit(EXIT_SUCCESS);
}

/**
 * cmdId - command Idx
 * @data: the data structure
 *
 * Return: Nothing
 */

void cmdId(shell_t *data)
{
	data->index += 1;
}
