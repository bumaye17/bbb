/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:17:36 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 23:21:57 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char **argv)
{
	char *str;
	int a;
	int i;
	t_sq *emp;
	t_sq *obs;

	i = 1;
	a = 123456789;
	if (argc < 2)
	{
		str = read_input();
		a = read_map(str, &obs, &emp);
		ft_putnbr(a);
	}
	else
	{
		while(i < argc)
		{
			a = read_map(argv[i], &obs, &emp);
			ft_putnbr(a);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
