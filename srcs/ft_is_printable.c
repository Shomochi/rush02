/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_printable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smotomur <smotomur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 21:25:07 by smotomur          #+#    #+#             */
/*   Updated: 2020/08/23 17:19:37 by smotomur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_printable(char c)
{
	if (c < ' ' || c > '~')
		return (0);
	else
		return (1);
}
