/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:35:34 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:42:53 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solonglib.h"

int	*handle_moves(t_data *mlx)
{
	int	*pos;

	pos = NULL;
	if (mlx->moves == 0)
	{
		pos = ft_pos(mlx->join);
		mlx->ancho = pos[0];
		mlx->largo = pos[1];
	}
	return (pos);
}

int	map_weidth(t_data *mlx)
{
	int	i;

	i = 0;
	while (mlx->join[i] != '\n')
		i++;
	return (i + 1);
}

int	map_long(t_data *mlx)
{
	int	i;
	int	rows;

	rows = 0;
	i = 0;
	while (mlx->join[i])
	{
		if (mlx->join[i] == '\n')
			rows++;
		i++;
	}
	return (rows);
}

int	n_coins(t_data *mlx)
{
	int	i;
	int	n_coins;

	n_coins = 0;
	i = 0;
	while (mlx->join[i])
	{
		if (mlx->join[i] == 'C')
			n_coins++;
		i++;
	}
	return (n_coins);
}

void	handle_coins(t_data *mlx)
{
	int	pos;

	pos = ((map_weidth(mlx)) * (mlx->largo / 50) + mlx->ancho / 50);
	if (mlx->join[pos] == 'C')
	{
		mlx->join[pos] = '0';
		mlx->ncoins--;
	}
}
