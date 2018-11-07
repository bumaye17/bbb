/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:20:00 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 23:21:54 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void set_answer(t_sq **obs, t_sq **emp, int *m, int i)
{
	*m = *m + 1;
	(*obs)[0].y = (*emp)[i].y;
	(*emp)[0].y = (*emp)[i].x;
}
		

int search(t_sq **obs, t_sq **emp, int h, int w)
{
	int i;
	int b;
	int j;
	int m;

	m = 1;
	(*obs)[0].y = 0;
	(*emp)[0].y = 0;
	i = 1;
	j = 1;
	while (i <= (*emp)[0].x)
	{
		b = max_possible_sq((*emp)[i], h, w);
		skip_obs((*emp)[i], (*obs), &j);
		while (m <= b)
		{
			if(if_fits((*obs), j, (*emp)[i], max_c((*emp)[i], m)) == 1)
				set_answer(obs, emp, &m, i);
			else
				b = m - 1;
		}
		i++;
	}
	return (m - 1);
}	
