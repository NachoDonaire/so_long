/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_staff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:29:44 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:43:21 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solonglib.h"

char	*save_map_util(char *join)
{
	int	fd;

	fd = 0;
	while (join[fd])
	{
		if (join[fd] != '0' && join[fd] != '1'
			&& join[fd] != 'C' && join[fd] != 'E'
			&& join[fd] != 'P' && join[fd] != '\n')
			return (NULL);
		fd++;
	}
	return (join);
}

int	jumpy(char *join)
{
	int	i;
	int	jump;

	i = 0;
	jump = 0;
	while (join[i])
	{
		if (join[i] == '\n')
			jump++;
		i++;
	}
	return (jump);
}

int	check_player(char *join)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (join[i])
	{
		if (join[i] == 'P')
			player++;
		i++;
	}
	if (player != 1)
		return (0);
	return (1);
}

int	check_door(char *join)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (join[i])
	{
		if (join[i] == 'E')
			player++;
		i++;
	}
	if (player == 0)
		return (0);
	return (1);
}

int	check_coin(char *join)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (join[i])
	{
		if (join[i] == 'C')
			player++;
		i++;
	}
	if (player >= 1)
		return (0);
	return (1);
}
