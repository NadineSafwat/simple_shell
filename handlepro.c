#include "shell.h"

/**
 * get_line - recieves the line from the std input
 * @data: the data structure
 *
 * Return: positive or a negative number
 */

int get_line(shell_t *data)
{
	char *csr_ptr, *end_ptr, c;
	size_t size = 256, read_st, len, nwsize;

	data->line = malloc(size * sizeof(char));
	if (data->line == NULL)
		return (-1);
	if (isatty(STDIN_FILENO))
		PRINT("$ ");
	for (csr_ptr = data->line, end_ptr = data->line + size;;)
	{
		read_st = read(STDIN_FILENO, &c, 1);
		if (read_st == 0)
			return (-1);
		*csr_ptr++ = c;
		if (c == '\n')
		{
			*csr_ptr = '\0';
			return (1);
		}
		if (csr_ptr + 2 >= end_ptr)
		{
			nwsize = size * 2;
			len = csr_ptr - data->line;
			data->line = _realloc(data->line, size * sizeof(char),
			nwsize * sizeof(char));
			if (data->line == NULL)
				return (-1);
			size = nwsize;
			end_ptr = data->line + size;
			csr_ptr = data->line + len;
		}
	}
}

/**
 * cmdpro - execute process
 * @data: the data structure
 *
 * Return: 0 on success, -1 on failure
 */

int cmdpro(shell_t *data)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(data->cmd, data->args, environ) < 0)
			data->error_msg = _strdup("not found\n");
		return (-1);
	}
	else
	{
		waitpid(pid, &stat, WUNTRACED);
	}
	return (0);
}

#define DELIMITER " \r\v\n\a\t"
/**
 * linesplit - splits line o specific delim
 * @data: the data structure
 *
 * Return: 0 or -1
 */

int linesplit(shell_t *data)
{
	char *del;
	size_t size, nwsize, i;

	size = 64;
	i = 0;
	if (_strcmp(data->line, "\n") == 0)
		return (-1);
	data->args = malloc(size * sizeof(char *));
	if (data->args == NULL)
		return (-1);
	del = strtok(data->line, DELIMITER);
	if (del == NULL)
		return (-1);
	while (del)
	{
		data->args[i++] =  del;
		if (i + 2 >= size)
		{
			nwsize = size * 2;
			data->args = _realloc(data->args, size * sizeof(char *),
			nwsize * sizeof(char *));
			if (data->args == NULL)
				return (-1);
			size = nwsize;
		}
		del = strtok(NULL, DELIMITER);
	}
	data->args[i] = NULL;
	return (0);
}
#undef DELIMITER

/**
 * write_history - prints error
 * @data: the data structure
 *
 * Return: 1 o success or -1 on failure
 */

int write_history(shell_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "this is a line of history";
	ssize_t fd, w;
	int len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[len])
			len++;
		w = write(fd, line_of_history, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
