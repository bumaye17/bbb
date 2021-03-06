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

int	max_possible_sq(t_sq sq, int t_h, int t_w)
{
	t_h = t_h - sq.y;
	t_w = t_w - sq.x;
	
	if (t_h <= t_w)
		return (t_h);
	else
		return (t_w);
}
	
t_sq	max_c(t_sq origin, int dim)
{
	t_sq dest;

	dest.x = origin.x + dim - 1;
	dest.y = origin.y + dim - 1;
	return(dest);
}

int	is_inside_sq(t_sq sq, t_sq orig, t_sq dest)
{
	if ((sq.x >= orig.x) && (sq.y >= orig.y) &&
			(sq.x <= dest.x) && (sq.y <= dest.y))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	if_fits(t_sq *obs, int i, t_sq min, t_sq max)
{
	while(i <= obs[0].x)
	{
		if (is_inside_sq(obs[i], min, max) == 1)
			return (0);
		if (((obs[i]).x >= max.x) && ((obs[i]).y >= max.y))
			i = obs[0].x + 1;
		else
			i++;
	}
	return (1);
}

int	skip_obs(t_sq org, t_sq *obs, int *i)
{
	while (((obs[*i]).x <= org.x) && ((obs[*i]).y <= org.y))
		*i = *i + 1;
	return (*i);
}	
