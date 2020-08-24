/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasegaw <dhasegaw@stydebt.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:14:13 by otaishi           #+#    #+#             */
/*   Updated: 2020/08/23 20:08:53 by dhasegaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}					t_dict;

void				ft_putstr(char *str);
int					ft_is_space(char c);
int					ft_is_printable(char c);
int					ft_is_numeric(char c);
int					ft_strlen(char *str);
int					ft_strcmp(char *s1, char *s2);
void				ft_puterror(void);
void				ft_putdicterror(void);
void				ft_print(char *str);
int					ft_str_separate(char *str);
void				num2words(char *num);
int					num_check(char *num);
int					check_value(char *key);
t_dict				*create_record(char *key, char *value);
void				prepend_record(char *key, char *value);
void				free_dict(void);
char				*get_value(char *key);

extern int			g_flag;
extern int			g_unit;
extern int			g_check;
extern t_dict		*g_dict;

#endif
