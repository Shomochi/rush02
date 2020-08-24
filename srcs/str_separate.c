/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_separate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smotomur <smotomur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 21:27:58 by smotomur          #+#    #+#             */
/*   Updated: 2020/08/23 21:37:15 by smotomur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		find_value(char *str, int i, char *value)
{
	int	j;

	j = 0;
	while (ft_is_space(str[i]) == 1)
		i++;
	if (ft_is_printable(str[i]) == 0)
		return (0);
	while (str[i] != '\0' && ft_is_printable(str[i]) == 1)
	{
		value[j] = str[i];
		i++;
		j++;
	}
	value[j] = '\0';
	return (1);
}

int		ft_find_colon(char *str)
{
	int i;

	i = 0;
	while (str[i] != ':')
	{
		i++;
	}
	return (i);
}

int		find_key(char *str, char *key)
{
	int		i;
	int		colon;

	colon = ft_find_colon(str);
	if (ft_is_numeric(str[0]) == 0)
		return (0);
	else
		key[0] = str[0];
	i = 1;
	while (i < colon && ft_is_numeric(str[i]))
	{
		key[i] = str[i];
		i++;
	}
	while (i < colon)
	{
		if (ft_is_space(str[i]) == 0)
			return (0);
		else
			i++;
	}
	key[i] = '\0';
	i++;
	return (i);
}

int		ft_str_separate(char *str)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	if (str[0] == '\0')
		return (0);
	key = (char*)malloc(ft_strlen(str) + 1);
	value = (char*)malloc(ft_strlen(str) + 1);
	i = find_key(str, key);
	j = find_value(str, i, value);
	if (i == 0 || j == 0)
	{
		ft_putdicterror();
		return (1);
	}
	else
		prepend_record(key, value);
	return (0);
}
