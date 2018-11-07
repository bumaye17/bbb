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
	int i;

	i = 1;;
	if (argc < 2)
	{
		str = read_input();
		bsq(str);
	}
	else
	{
		while(i < argc)
		{
			str = read_file(argv[i]);
			bsq(str);
			i++;
			if (i != argc)
				ft_putchar('\n');
		}
	}
	return (0);
}
