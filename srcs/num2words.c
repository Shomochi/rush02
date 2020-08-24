/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num2words.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasegaw <dhasegaw@stydebt.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:57:25 by dhasegaw          #+#    #+#             */
/*   Updated: 2020/08/23 23:28:00 by dhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_unit(int digit)
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
	ft_print(get_value(unit));
	free(unit);
	unit = (void*)0;
}

int		print_1d(char *num)
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
	ft_print(get_value(tmp));
	return (1);
}

int		print_2d(char *num)
{
	char tmp[3];
	char c[2];

	tmp[0] = *num;
	if (tmp[0] == '0')
	{
		print_1d(num + 1);
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
		ft_print(get_value(tmp));
		ft_print(get_value(c));
	}
	else
		ft_print(get_value(tmp));
	return (2);
}

int		print_3d(char *num)
{
	char c[3];

	c[0] = num[0];
	if (c[0] == '0')
	{
		print_2d(num + 1);
		return (3);
	}
	g_unit = 0;
	c[1] = '\0';
	ft_print(get_value(c));
	ft_print(get_value("100"));
	c[0] = num[1];
	c[1] = num[2];
	c[2] = '\0';
	if (c[0] == '0' && c[1] == '0')
		return (3);
	print_2d(num + 1);
	return (3);
}

void	num2words(char *num)
{
	int digit;
	int step;

	digit = ft_strlen(num);
	if (*num == '0')
		ft_print(get_value("0"));
	else
	{
		while (digit > 0)
		{
			if (digit % 3 == 0)
				step = print_3d(num);
			else if (digit % 3 == 2)
				step = print_2d(num);
			else
				step = print_1d(num);
			digit = digit - step;
			if (digit == 0)
				break ;
			print_unit(digit);
			while (step--)
				num++;
		}
	}
	ft_putstr("\n");
}
