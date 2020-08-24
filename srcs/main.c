/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasegaw <dhasegaw@stydebt.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:14:13 by otaishi           #+#    #+#             */
/*   Updated: 2020/08/23 21:13:01 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int g_flag;
int g_unit;
int g_check;

int		read_arg1_func(void)
{
	int		i;
	int		fd;
	char	buf;
	char	moji[1024];

	fd = open("dict/numbers.dict", O_RDONLY);
	if (fd == -1)
		ft_putdicterror();
	while (read(fd, &buf, 1))
	{
		i = 0;
		while (!(buf == '\n'))
		{
			moji[i] = buf;
			i++;
			if (!(read(fd, &buf, 1)))
				break ;
		}
		moji[i] = '\0';
		if (ft_str_separate(moji))
			return (1);
	}
	if (close(fd) == -1)
		ft_putdicterror();
	return (0);
}

int		read_arg2_func(char *str)
{
	int		i;
	int		fd;
	char	buf;
	char	moji[1024];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		ft_putdicterror();
	while (read(fd, &buf, 1))
	{
		i = 0;
		while (!(buf == '\n'))
		{
			moji[i] = buf;
			i++;
			if (!(read(fd, &buf, 1)))
				break ;
		}
		moji[i] = '\0';
		if (ft_str_separate(moji))
			return (1);
	}
	if (close(fd) == -1)
		ft_putdicterror();
	return (0);
}

int		ft_argv_check(char *str)
{
	if (*str == '\0' || ((ft_strlen(str) > 1) && (*str == '0')))
	{
		ft_puterror();
		return (1);
	}
	while (*str)
	{
		if (!ft_is_numeric(*str))
		{
			ft_puterror();
			return (1);
		}
		str++;
	}
	return (0);
}

int		argc3(char *argv1, char *argv2)
{
	if (ft_argv_check(argv2))
		return (1);
	if (read_arg2_func(argv1))
		return (1);
	if (num_check(argv2))
		num2words(argv2);
	else
	{
		ft_putdicterror();
		return (1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	g_flag = 0;
	g_unit = 0;
	g_check = 1;
	if (!((argc == 2) || (argc == 3)))
		ft_puterror();
	if (argc == 2)
	{
		if (ft_argv_check(argv[1]))
			return (1);
		if (read_arg1_func())
			return (1);
		if (num_check(argv[1]))
			num2words(argv[1]);
		else
		{
			ft_putdicterror();
			return (1);
		}
	}
	if (argc == 3)
		if (argc3(argv[1], argv[2]))
			return (1);
	return (0);
}
