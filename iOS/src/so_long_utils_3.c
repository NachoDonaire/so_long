/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:04 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:43:08 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solonglib.h"

void	put_floor(t_data *mlx)
{
	char	*img;

	img = mlx_xpm_file_to_image(mlx->mlx,
			"img/bloqueoff", &mlx->img_ancho, &mlx->img_alto);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->ancho, mlx->largo);
	mlx_destroy_image(mlx->mlx, img);
}

void	put_floor_hero(t_data *mlx)
{
	put_floor(mlx);
	put_personaje(mlx);
}

void	put_floor_coin(t_data *mlx)
{
	put_floor(mlx);
	put_coin(mlx);
}

void	plus_a_l(t_data *mlx)
{
	mlx->ancho = 0;
	mlx->largo = mlx->largo + 50;
}
