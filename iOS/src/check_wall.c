/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:02:47 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 14:21:07 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solonglib.h"

int	check_wall_largo_up(t_data *mlx)
{
	int	pos;

	pos = ((map_weidth(mlx)) * ((mlx->largo - 50) / 50) + mlx->ancho / 50);
	if (mlx->join[pos] == '1')
		return (0);
	else if (mlx->join[pos] == 'E')
	{
		put_floor(mlx);
		mlx->largo -= 50;
		put_personaje(mlx);
		mlx->moves++;
		return (0);
	}
	return (1);
}

int	check_wall_largo_down(t_data *mlx)
{
	int	pos;

	pos = ((map_weidth(mlx)) * ((mlx->largo + 50) / 50) + mlx->ancho / 50);
	if (mlx->join[pos] == '1')
	{
		return (0);
	}
	else if (mlx->join[pos] == 'E')
	{
		put_floor(mlx);
		mlx->largo += 50;
		put_personaje(mlx);
		mlx->moves++;
		return (0);
	}
	return (1);
}

void	close_win(t_data *mlx)
{
	int	pos;

	pos = ((map_weidth(mlx)) * ((mlx->largo) / 50) + mlx->ancho / 50);
	if (mlx->ncoins <= 0 && mlx->join[pos] == 'E')
	{
		write(1, "You won!", 8);
		exit_and_free(mlx);
	}
}

int	check_wall_ancho_right(t_data *mlx)
{
	int	pos;
	int	*loc;

	loc = handle_moves(mlx);
	if (mlx->moves == 0)
		mlx->ancho = loc[0];
	free(loc);
	pos = ((map_weidth(mlx)) * ((mlx->largo) / 50) + (mlx->ancho + 50) / 50);
	if (mlx->join[pos] == '1')
		return (0);
	else if (mlx->join[pos] == 'E')
	{
		put_floor(mlx);
		mlx->ancho = mlx->ancho + 50;
		put_personaje(mlx);
		mlx->moves++;
		return (0);
	}
	return (1);
}

int	check_wall_ancho_left(t_data *mlx)
{
	int	pos;

	pos = ((map_weidth(mlx)) * ((mlx->largo) / 50) + (mlx->ancho - 50) / 50);
	if (mlx->join[pos] == '1')
		return (0);
	else if (mlx->join[pos] == 'E')
	{
		put_floor(mlx);
		mlx->ancho -= 50;
		put_personaje(mlx);
		mlx->moves++;
		return (0);
	}
	return (1);
}
