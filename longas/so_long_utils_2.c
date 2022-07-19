/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:36:04 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:43:04 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solonglib.h"

int	ft_ancho(char *join)
{
	int	i;

	i = 0;
	while (join[i] != '\n')
		i++;
	return (i);
}

int	alto(char *join)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (join[i])
	{
		if (join[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	put_open_door(t_data *mlx)
{
	char	*img;
	int		i;

	mlx->k = 0;
	mlx->col = 0;
	i = 0;
	while (mlx->join[i])
	{
		if (mlx->join[i] == 'E')
		{
			mlx->k -= 50;
			img = mlx_xpm_file_to_image(mlx->mlx, "img/porton_abertu.xpm",
					&mlx->img_ancho, &mlx->img_alto);
			mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->k, mlx->col);
			mlx_destroy_image(mlx->mlx, img);
			mlx->k += 50;
		}
		if (mlx->join[i] == '\n')
		{
			mlx->col = mlx->col + 50;
			mlx->k = 0;
		}
		i++;
		mlx->k = mlx->k + 50;
	}
}

int	exit_and_free(t_data *mlx)
{
	free(mlx->join);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(-1);
}

void	put_wall(t_data *mlx)
{
	char	*img;

	img = mlx_xpm_file_to_image(mlx->mlx, "img/murooff.xpm",
			&mlx->img_ancho, &mlx->img_alto);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->ancho, mlx->largo);
	mlx_destroy_image(mlx->mlx, img);
}
