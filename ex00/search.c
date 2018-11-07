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

int	max_possible_sq(int x, int y, int t_h, int t_w)
{
	t_h = t_h - y;
	t_w = t_w - x;
	
	if (t_h <= t_w)
		return (t_h);
	else
		return (t_w);
}
	
t_sq	max_coord(t_sq origin, int dim)
{
	t_sq dest;

	dest.x = origin.x + dim - 1;
	dest.y = origin.y + dim - 1;
	return(dest);
}

int	is_inside_sq(t_sq sq, t_sq or, t_sq de)
{
	if ((sq.x >= or.x) && (sq.y >= or.y) && (sq.x <= de.x) &&
			(sq.y <= de.y))
		return (1);
	else
		return (0);
}

int	if_fits(t_sq *obs, int i, t_sq min, t_sq max)
{
	while(i < obs[0].x)
	{
		if (is_inside_sq(obs[i], min, max) == 1)
			return (0);
		if ((obs[i].x >= max.x) && (obs[i].y >= max.y))
			i = obs[0].x;
		else
			i++;
	}
	return (1);
}

int	skip_obs(t_sq org, t_sq *obs, int i)
{
	while ((obs[i].x < org.x) && (obs[i].y < org.y))
		i++;
	return (i);
}	
