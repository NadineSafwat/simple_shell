#include "shell.h"

/**
 * _strlen - gets the length of the string
 * @s: the string input
 * Return: the length of the input string
 */

int _strlen(char *s)
{
	int i, j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

/**
 * _strchr - searches for a charecter in a string
 * @s: pointer to a string
 * @c: charecter to be searched for
 * Return: pointer to the first occur of c or NULL is not found
 */

char *_strchr(char *s, char c)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			return (s + i);
		}
		i++;
	}
	if (*(s + i) == c)
	{
		return (s + i);
	}
	return ('\0');
}

/**
 * _strcpy - copy a string to another
 * @dest: destination
 * @src: parameter with string
 * Return: copied string
 */

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}

/**
 * _strcmp - compairing two strings
 * @s1: first string
 * @s2: second string
 * Return: 0, 1 or -1
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
		{
			break;
		}
		op = *(s1 + i) - *(s2 + i);
		i++;
	}
	return (op);
}
