#include "shell.h"

/**
 * _strncat - append n bytes of stc to another string
 * @dest: first string
 * @src: second string
 * @n: number of bytes
 * Return: appended string
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strdup - dupicates the string
 * @str: given string
 *
 * Return: a pointer to the duplicated string or NULL
 */

char *_strdup(char *str)
{
	char *dupl;

	if (str == NULL)
	{
		return (NULL);
	}
	dupl = malloc(_strlen(str) + 1);
	if (dupl == NULL)
	{
		return (NULL);
	}
	_strcpy(dupl, str);
	return (dupl);
}

/**
 * _strcat - concatenates two string
 * @str1: the first string
 * @str2: the second string
 *
 * Return: a pointer to the new string or NULL
 */

char *_strcat(char *str1, char *str2)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
	{
		return (NULL);
	}
	*result = '\0';
	while (str1[j])
	{
		result[i++] = str1[j++];
	}
	result[i++] = '/';
	j = 0;
	while (str2[j])
	{
		result[i++] = str2[j++];
	}
	result[i] = '\0';
	return (result);
}

/**
 * _isalpha - check if the input is a letter
 * @c: the character to be checked
 *
 * Return: 1 if letter, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (-1);
}
