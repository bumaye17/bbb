/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 20:51:29 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/04 22:58:41 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdlib.h>

t_st	*create_new_st(char c)
{
	t_st *new_st;

	new_st = (t_st*)malloc(sizeof(t_st));
	if (new_st)
	{
		new_st->next = 0;
		new_st->c = c;
	}
	return (new_st);
}

void	add_st(t_st **begin_st, char c)
{
	t_st *new_st;

	new_st = create_new_st(c);
	new_st->next = *begin_st;
	*begin_st = new_st;
}

void	free_st(t_st **st)
{
	t_st *copy;

	copy = (*st)->next;
	(*st)->next = 0;
	free(*st);
	*st = copy;
}
