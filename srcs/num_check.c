/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasegaw <dhasegaw@stydebt.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:57:25 by dhasegaw          #+#    #+#             */
/*   Updated: 2020/08/23 23:28:44 by dhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	check_unit(int digit)
{
	char	*unit;
	int		i;

	if (digit < 3 || g_unit == 1)
		return ;
	unit = (char*)malloc(sizeof(char) * (digit + 2));
	unit[0] = '1';
	unit[digit + 1] = '\0';
	i = 1;
	while (i < digit + 1)
	{
		unit[i] = '0';
		i++;
	}
	g_check *= check_value(unit);
	free(unit);
	unit = (void*)0;
}

int		check_1d(char *num)
{
	char tmp[2];

	tmp[0] = *num;
	if (tmp[0] == '0')
	{
		g_unit = 1;
		return (1);
	}
	g_unit = 0;
	tmp[1] = '\0';
	g_check *= check_value(tmp);
	return (1);
}

int		check_2d(char *num)
{
	char tmp[3];
	char c[2];

	tmp[0] = *num;
	if (tmp[0] == '0')
	{
		check_1d(num + 1);
		return (2);
	}
	g_unit = 0;
	tmp[1] = *(num + 1);
	tmp[2] = '\0';
	if (tmp[0] != '1' && tmp[1] != '0')
	{
		c[0] = tmp[1];
		c[1] = '\0';
		tmp[1] = '0';
		g_check *= check_value(tmp);
		g_check *= check_value(c);
	}
	else
		g_check *= check_value(tmp);
	return (2);
}

int		check_3d(char *num)
{
	char c[3];

	c[0] = num[0];
	if (c[0] == '0')
	{
		check_2d(num + 1);
		return (3);
	}
	g_unit = 0;
	c[1] = '\0';
	g_check *= check_value(c);
	g_check *= check_value("100");
	c[0] = num[1];
	c[1] = num[2];
	c[2] = '\0';
	if (c[0] == '0' && c[1] == '0')
		return (3);
	check_2d(num + 1);
	return (3);
}

int		num_check(char *num)
{
	int digit;
	int step;

	digit = ft_strlen(num);
	if (num[0] == '0')
		g_check *= check_value("0");
	else
	{
		while (digit > 0)
		{
			if (digit % 3 == 0)
				step = check_3d(num);
			else if (digit % 3 == 2)
				step = check_2d(num);
			else
				step = check_1d(num);
			digit = digit - step;
			if (digit == 0)
				break ;
			check_unit(digit);
			while (step--)
				num++;
		}
	}
	return (g_check);
}
