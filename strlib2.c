#include "shell.h"

/**
 * _strchr - custum strchr
 * @s: string
 * @c: character
 *
 * Return: string
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

/**
 * _strcmp - compare strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 or dif
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}
