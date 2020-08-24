/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasegaw <dhasegaw@stydebt.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 22:16:41 by smotomur          #+#    #+#             */
/*   Updated: 2020/08/23 17:17:18 by smotomur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print(char *str)
{
	if (g_flag)
		ft_putstr(" ");
	ft_putstr(str);
	g_flag = 1;
}