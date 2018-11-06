/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:20:00 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 23:21:54 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdlib.h>

int		validate_map_info(char *str)
{
	int i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
		i++;
	if (!(str[i] && str[i + 1] && str[i +2]))
		return (0);
	if ((str[i] == str[i + 1]) || (str[i] == str[i + 2]) ||
			(str[i + 1] == str[i + 2]))
		return (0);
	if (str[i + 3] != '\n')
		return (0);
	return (1);
}

void	read_map_info(char *str, int *lines, char **symbols)
{
	int j;
	int k;

	k = 0;
	*lines = parse_nb(str);
	j = 0;
	*symbols = malloc(sizeof(char) * 4);
	while ((str[j] >= '0') && (str[j] <= '9'))
		j++;
	while (k < 3)
	{
		(*symbols)[k] = str[j];
		j++;
		k++;
	}
}

int		count_lines(char *str)
{
	int i;
	int count;
	
	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		check_symb(char *str, char empty, char obst)
{
	int i;
	int j;
	int count;

	i = skip_first_line(str);
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while ((str[i] != '\n') && (str[i] != '\0'))
		{
			if ((str[i] != empty) && (str[i] != obst))
				return (0);
			j++;
			i++;
		}
		if (count < 1)
			count = j;
		if ((j != count) || (j == 0))
			return (0);
		i++;
	}
	return (1);
}


int validate_map(char *str)
{
	int lines;
	char *symb;
	if ((validate_map_info(str) == 1))
	{
		read_map_info(str, &lines, &symb);
		if (count_lines(str) != lines)
			return (0);
		if (check_symb(str, symb[0], symb[1]) == 0)
			return (0);
		return (1);
	}
	else
		return (0);
}
