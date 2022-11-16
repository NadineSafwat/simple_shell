#include "shell.h"
/**
 * printerr - prints error
 * @data: the data structure
 *
 * Return: 0 on success
 */

int printerr(shell_t *data)
{
	char *idx = _itoa(data->index);

	PRINT("hsh: ");
	PRINT(idx);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->error_msg);
	free(idx);
	return (0);
}

/**
 * _itoa - Converts an integer value to a null-terminated string
 * @n: the integer
 *
 * Return: a pointer to the array
 */

char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = ilen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	reva(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * _atoi - converts the string argument to an integer
 * @c: the character of the string
 *
 * Return: the converted int
 */
int _atoi(char *c)
{
	unsigned int val = 0;
	int sign = 1;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sign * val);
}

/**
 * ilen - gets the length of interger
 * @num: the number
 *
 * Return: the length of the number
 */
int ilen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
