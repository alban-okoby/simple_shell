#include "shell.h"

/**
 * to_unset_alias - This function unsets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int to_unset_alias(info_s *info, char *str)
{
	char *p, cr;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	cr = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_str_start(info->alias, str, -1)));
	*p = cr;
	return (ret);
}

/**
 * to_set_alias - this function sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int to_set_alias(info_s *info, char *str)
{
	char *v;

	v = _strchr(str, '=');
	if (!v)
		return (1);
	if (!*++v)
		return (to_unset_alias(info, str));

	to_unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * to_print_alias - That function prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int to_print_alias(list_s *node)
{
	char *pr = NULL, *a = NULL;

	if (node)
	{
		pr = _strchr(node->str, '=');
		for (a = node->str; a <= pr; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(pr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * to_handle_alias - That function mimics the alias builtin (man alias)
 * @info: contains simulated arguments for a function pointer,
 * allowing for a consistent function prototype
 * Return: Always 0
 */
int to_handle_alias(info_s *info)
{
	int i = 0;
	char *p = NULL;
	list_s *my_node = NULL;

	if (info->argc == 1)
	{
		my_node = info->alias;
		while (my_node)
		{
			to_print_alias(my_node);
			my_node = my_node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			to_set_alias(info, info->argv[i]);
		else
			to_print_alias(node_str_start(info->alias, info->argv[i], '='));
	}

	return (0);
}

/**
 * to_change_alias - That function replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int to_change_alias(info_s *info)
{
	int i;
	list_s *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_str_start(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}

	return (1);
}

