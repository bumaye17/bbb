/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwalter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:14:16 by mwalter           #+#    #+#             */
/*   Updated: 2018/11/05 21:26:27 by mwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_nb(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	skip_first_line(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\n')
		i++;
	i++;
	return(i);
}

void	increment_i_j(int *i, int *j)
{
	*i = *i + 1;
	*j = *j + 1;
}
	
