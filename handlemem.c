#include "shell.h"

/**
 * _memset - function that fills memory with a constant byte
 * @s: pointer to charecter
 * @b: constant byte
 * @n: number of bytes to be filled
 * Return: pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}

/**
 * _memcpy - copies memory data
 * @dest: destination variable
 * @src: source string
 * @n: number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}

/**
 * datafree - frees the data stored in the structure
 * @data: the data structure
 *
 * Return: zero when success
 */
int datafree(shell_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}

/**
 * _realloc - reallocates memory
 * @ptr: pointer to the previous memory
 * @presize: the size before relocation
 * @postsize: the size after relocation
 *
 * Return: a pointer to the newly allocated memory
 */
void *_realloc(void *ptr, unsigned int presize, unsigned int postsize)
{
	void *result;

	if (postsize == presize)
		return (ptr);
	if (postsize == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(postsize);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		arrayf(result, '\0', postsize);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, presize);
		free(ptr);
	}
	return (result);
}
