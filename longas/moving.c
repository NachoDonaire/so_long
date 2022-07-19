/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:32:00 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:29:53 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solonglib.h"

int	move_right(t_data *mlx)
{
	int	*pos;
	int	loc;

	pos = handle_moves(mlx);
	if (check_wall_ancho_right(mlx) == 0)
		return (0);
	loc = ((map_weidth(mlx)) * ((mlx->largo) / 50) + (mlx->ancho) / 50);
	if (mlx->join[loc] == 'E')
		handle_door(mlx);
	else
		put_floor(mlx);
	if (mlx->moves != 0)
		mlx->ancho = mlx->ancho + 50;
	else if (mlx->moves == 0)
		mlx->ancho = pos[0] + 50;
	put_floor(mlx);
	put_personaje(mlx);
	mlx->moves++;
	handle_coins(mlx);
	put_moves(mlx);
	free(pos);
	return (0);
}

int	move_left(t_data *mlx)
{
	int	*pos;
	int	loc;

	pos = handle_moves(mlx);
	if (check_wall_ancho_left(mlx) == 0)
		return (0);
	loc = ((map_weidth(mlx)) * ((mlx->largo) / 50) + (mlx->ancho) / 50);
	if (mlx->join[loc] == 'E')
		handle_door(mlx);
	else
		put_floor(mlx);
	if (mlx->moves != 0)
		mlx->ancho = mlx->ancho - 50;
	else
		mlx->ancho = pos[0] - 50;
	if (mlx->join[loc] == 'E')
		handle_door(mlx);
	else
		put_floor(mlx);
	put_floor(mlx);
	put_personaje(mlx);
	mlx->moves++;
	handle_coins(mlx);
	put_moves(mlx);
	free(pos);
	return (0);
}

int	move_up(t_data *mlx)
{
	int	*pos;
	int	loc;

	pos = handle_moves(mlx);
	if (check_wall_largo_up(mlx) == 0)
		return (0);
	loc = ((map_weidth(mlx)) * ((mlx->largo) / 50) + (mlx->ancho) / 50);
	if (mlx->join[loc] == 'E')
		handle_door(mlx);
	else
		put_floor(mlx);
	if (mlx->moves != 0)
		mlx->largo = mlx->largo - 50;
	else
		mlx->largo = pos[1] - 50;
	put_floor(mlx);
	put_personaje(mlx);
	mlx->moves++;
	handle_coins(mlx);
	put_moves(mlx);
	free(pos);
	return (0);
}

int	move_down(t_data *mlx)
{
	int	*pos;
	int	loc;

	pos = handle_moves(mlx);
	if (check_wall_largo_down(mlx) == 0)
		return (0);
	loc = ((map_weidth(mlx)) * ((mlx->largo) / 50) + (mlx->ancho) / 50);
	if (mlx->join[loc] == 'E')
		handle_door(mlx);
	else
		put_floor(mlx);
	if (mlx->moves != 0)
		mlx->largo = mlx->largo + 50;
	else
		mlx->largo = pos[1] + 50;
	put_floor(mlx);
	put_floor(mlx);
	put_personaje(mlx);
	mlx->moves++;
	handle_coins(mlx);
	put_moves(mlx);
	free(pos);
	return (0);
}
