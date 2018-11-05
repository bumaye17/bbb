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

	i = 1;
	a = 123456789;
	if (argc < 2)
	{
		str = read_input();
		a = validate_map(str);
		ft_putnbr(a);
	}
	else
	{
		while(i < argc)
		{
			a = validate_map(argv[i]);
			ft_putnbr(a);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
