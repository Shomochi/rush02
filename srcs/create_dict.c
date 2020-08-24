/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasegaw <dhasegaw@stydebt.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:16:41 by smotomur          #+#    #+#             */
/*   Updated: 2020/08/23 23:27:14 by dhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict *g_dict;

t_dict	*create_record(char *key, char *value)
{
	t_dict *ret;

	ret = (t_dict*)malloc(sizeof(t_dict));
	ret->key = key;
	ret->value = value;
	ret->next = 0;
	return (ret);
}

void	prepend_record(char *key, char *value)
{
	t_dict *tmp;

	if (!g_dict)
		g_dict = create_record(key, value);
	else
	{
		tmp = g_dict;
		g_dict = create_record(key, value);
		g_dict->next = tmp;
	}
}

void	free_dict(void)
{
	t_dict *tmp;

	while (g_dict)
	{
		tmp = g_dict;
		g_dict = g_dict->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp->key = (void*)0;
		tmp->value = (void*)0;
		tmp = (void*)0;
	}
}

char	*get_value(char *key)
{
	t_dict *tmp;

	tmp = g_dict;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->key, key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

int		check_value(char *key)
{
	t_dict *tmp;

	tmp = g_dict;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->key, key)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
