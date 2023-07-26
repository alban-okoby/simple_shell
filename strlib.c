#include "shell.h"

/**
 * _strncpy - copy n bytes from src to dest
 * @dest: destination string
 * @src: string source
 * @n: nuber of bytes to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * custom_concat - concate two stings with
 * separator between them
 * @str1: first string
 * @str2: second string
 * @separator: the separaator
 *
 * Return: concaatenation of the three
 */
char *custom_concat(char *str1, char *str2, char separator)
{
	size_t len1, len2, sep_len, i;
	char *result;

	len1 = len2 = 0;
	sep_len = 1;
	while (str1[len1] != '\0')
		len1++;
	while (str2[len2] != '\0')
		len2++;
	result = (char *)malloc(len1 + len2 + sep_len + 1);
	if (result == NULL)
		return (NULL);

	_strncpy(result, str1, len1);
	result[len1] = separator;
	for (i = 0; i < len2; i++)
		result[len1 + sep_len + i] = str2[i];
	result[len1 + sep_len + len2] = '\0';
	return (result);
}

/**
 * _strncmp - compare n bytes of 2 strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 *
 * Return: 0 or -15
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}

/**
 * _strdup - dupmicate string
 * @s: string to dup
 *
 * Return: the resulting string
 */
char *_strdup(const char *s)
{
	int i, len = 0;
	char *new_str;

	if (s == NULL)
		return (NULL);
	while (s[len] != '\0')
		len++;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		new_str[i] = s[i];
	return (new_str);
}

/**
 * intToString - Convert int in string
 * @num: int to convert
 *
 * Return: the string resulting from num
 */
char *intToString(int num)
{
	int i, len = 1;
	int temp = num;
	char *str;

	while (temp /= 10)
	{
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = len - 1;
	str[len] = '\0';
	while (num != 0)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}
	return (str);
}
