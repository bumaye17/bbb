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

typedef struct          s_sq
{
	int	x;
	int	y;
}			t_sq;



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
int     			check_symb(char *str, char empty, char obst, int *n_obs);
int 				validate_map(char *str, int *n_obs);
char				*read_input(void);
int				skip_first_line(char *str);
void				increment_i_j(int *i, int *j);
void				read_values(t_sq **list, int x, int y, int *count);
void				read_symbols(char *str, char *symb, t_sq **obs, t_sq **emp);
int				read_map(char *str, t_sq **obs, t_sq **emp);

#endif
