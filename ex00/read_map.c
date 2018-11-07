/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:20:00 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 23:21:54 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdlib.h>

void read_values(t_sq **list, int x, int y, int *count)
{
	((*list)[*count]).x = x;
	((*list)[*count]).y = y;
	*count = *count + 1;
}
	

void read_symbols(char *str, char *symb, t_sq **obs, t_sq **emp)
{
	int i;
	int x;
	int y;
	int c_obs;
	int c_emp;

	i = skip_first_line(str);
	c_obs = 1;
	c_emp = 1;
	y = 0;
	while (str[i])
	{
		x = 0;
		while (str[i] != '\n')
		{
			if (str[i] == symb[0])
				read_values(emp, x, y, &c_emp);
			if (str[i] == symb[1])
				read_values(obs, x, y, &c_obs);
			x++;
			i++;
		}
		i++;
		y++;
	}
}

void print_list(t_sq **list, int length)
{
	int i;
	i = 0;
	while (i < length)
	{
		ft_putnbr(((*list)[i]).y);
		ft_putchar('-');
		ft_putnbr(((*list)[i]).x);
		ft_putchar('\n');
		i++;
	}
}


int read_map(char *str, t_sq **obs, t_sq **emp)
{
	int n_obs;
	int n_emp;
	char *symb;
	int lines;
	int a;
	
	n_obs = 0;
	n_emp = validate_map(str, &n_obs);
	if (n_emp == 0)
	{
		symb = 0;
		return (0);
	}
	else
	{
		*obs = malloc(sizeof(t_sq*) * (n_obs + 1));
		n_emp = n_emp * parse_nb(str) - n_obs;
		read_map_info(str, &lines, &symb);
		*emp = malloc(sizeof(t_sq*) * (n_emp + 1));
		(*obs)[0].x = n_obs;
		(*emp)[0].x = n_emp;
		read_symbols(str, symb, obs, emp);
		a = search(obs, emp, lines, (n_obs + n_emp) / lines);
		return (a);
	}
}

void	bsq(char *str)
{
	t_sq *obs;
	t_sq *emp;
	int m;

	obs = 0;
	emp = 0;
	m = read_map(str, &obs, &emp);
	if (m == 0)
		ft_puterror("error\n");
	else
	{
		print_map(m, obs[0].y, emp[0].y, str);
		free(obs);
		free(emp);
	}
}
		
		

void print_map(int m, int y_o, int x_o, char *str)
{
	int i;
	int x;
	int y;
	char full;

	i = skip_first_line(str);
	full = str[i - 2];
	y = 0;
	while (str[i])
	{
		x = 0;
		while (str[i] != '\n')
		{
			if ((x >= x_o) && (y >= y_o) && (x <=
					x_o + m - 1) && (y <= y_o + m - 1))
				ft_putchar(full);
			else
				ft_putchar(str[i]);
			x++;
			i++;
		}
		ft_putchar('\n');
		i++;
		y++;
	}
}
