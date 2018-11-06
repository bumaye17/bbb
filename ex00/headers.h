/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 22:00:42 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 21:45:45 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

typedef struct		s_st
{
	struct s_st		*next;
	char			c;
}					t_st;

void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int nb);
int					parse_nb(char *str);
t_st				*create_new_st(char c);
void				add_st(t_st **begin_st, char c);
void				free_st(t_st **st);
int					validate_map_info(char * str);
void				read_map_info(char *str, int *lines, char **symbols);
int					count_lines(char *str);
int     			check_symb(char *str, char empty, char obst);
int 				validate_map(char *str);
char				*read_input(void);
int				skip_first_line(char *str);

#endif
