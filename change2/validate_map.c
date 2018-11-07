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
	int j;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (0);
	if ((str[i] < '0') || (str[i] > '9'))
		return (0);
	while ((str[i] != '\n') && (str[i] != '\0'))
		i++;
	if ((i < 4) || (i > 13))
		return (0);
	if ((str[i - 3] == str[i - 2]) || (str[i - 3] == str[i - 1]) ||
			(str[i - 1] == str[i - 2]))
		return (0);
	while (j < i - 3)
	{
		if ((str[j] < '0') || (str[j] > '9'))
			return (0);
		j++;
	}
	return (1);
}

void	read_map_info(char *str, int *lines, char **symbols)
{
	int i;
	int j;

	*lines = 0;
	i = 0;
	j = 0;
	*symbols = malloc(sizeof(char) * 4);
	while ((str[i] != '\n') && (str[i] != '\0'))
		i++;
	(*symbols)[2] = str[i - 1];
	(*symbols)[1] = str[i - 2];
	(*symbols)[0] = str[i - 3];
	while (j < i - 3)
	{
		*lines = *lines * 10 + str[j] - '0';
		j++;
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

int		check_symb(char *str, char empty, char obst, int *n_obs)
{
	int i;
	int j;
	int count;

	i = skip_first_line(str) - 1;
	j = 0;
	count = 0;
	*n_obs = 0;
	while (str[++i] != '\0')
	{
		j = 0;
		while ((str[i] != '\n') && (str[i] != '\0'))
		{
			if ((str[i] != empty) && (str[i] != obst))
				return (0);
			if (str[i] == obst)
				*n_obs = *n_obs + 1;
			increment_i_j(&i, &j);
		}
		if (count < 1)
			count = j;
		if ((j != count) || (j == 0))
			return (0);
	}
	return (count);
}


int validate_map(char *str, int *coun_ob)
{
	int lines;
	char *symb;

	if ((validate_map_info(str) == 1))
	{
		read_map_info(str, &lines, &symb);
		if (count_lines(str) != lines)
			return (0);
		if (check_symb(str, symb[0], symb[1], coun_ob) == 0)
			return (0);
		else
			return (check_symb(str, symb[0], symb[1], coun_ob));
	}
	else
		return (0);
}
