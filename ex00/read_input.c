/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 22:30:51 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 18:12:08 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "headers.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char	*read_input(void)
{
	t_st *input;
	char *str;
	char symb;
	int i;

	input = 0;
	i = 0;
	while (read(0, &symb, 1) > 0)
	{
		add_st(&input, symb);
		i++;
	}
	str = (char*)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';	
	while (i > 0)
	{
		str[i-1] = input->c;
		free_st(&input);
		i--;
	}
	return (str);
}
