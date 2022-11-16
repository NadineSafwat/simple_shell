#include "shell.h"

/**
 * handlesig - handle process signal
 * @sigId: the signal id
 * Return: nothing
 */

void handlesig(int sigId)
{
	if (sigId == SIGINT)
	{
		PRINT("\n");
		PRINT("$ ");
	}
}
