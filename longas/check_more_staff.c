/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_more_staff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:32:53 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:43:26 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solonglib.h"

int	check_square(char *join)
{
	int	i;
	int	k;
	int	square;

	i = 0;
	square = 0;
	k = 0;
	while (join[k] != '\n')
	{
		i++;
		k++;
	}
	k++;
	while (join[k])
	{
		while (join[k] != '\n')
		{
			k++;
			square++;
		}
		if (square != i)
			return (0);
		k++;
		square = 0;
	}
	return (1);
}
