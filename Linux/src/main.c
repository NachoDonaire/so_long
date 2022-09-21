/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:45:29 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:42:27 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solonglib.h"

void	put_coin(t_data *mlx)
{
	char	*img;

	img = mlx_xpm_file_to_image(mlx->mlx,
			"img/monedaoficial.xpm",
			&mlx->img_ancho, &mlx->img_alto);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->ancho, mlx->largo);
	mlx_destroy_image(mlx->mlx, img);
}

void	put_personaje(t_data *mlx)
{
	char	*img;

	img = mlx_xpm_file_to_image(mlx->mlx,
			"img/yoshioff.xpm",
			&mlx->img_ancho, &mlx->img_alto);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->ancho, mlx->largo);
	mlx_destroy_image(mlx->mlx, img);
}

void	put_door(t_data *mlx)
{
	char	*img;

	img = mlx_xpm_file_to_image(mlx->mlx,
			"img/portoon.xpm",
			&mlx->img_ancho, &mlx->img_alto);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, mlx->ancho, mlx->largo);
	mlx_destroy_image(mlx->mlx, img);
}

void	draw_map(t_data *mlx, char *join)
{
	int		i;

	i = 0;
	mlx->ancho = 0;
	mlx->largo = 0;
	mlx->win = mlx_new_window(mlx->mlx,
			ft_ancho(join) * 50, alto(join) * 50, "Prooof");
	while (join[i])
	{
		if (join[i] == '1')
			put_wall(mlx);
		else if (join[i] == '0')
			put_floor(mlx);
		else if (join[i] == 'C')
			put_floor_coin(mlx);
		else if (join[i] == 'P')
			put_floor_hero(mlx);
		else if (join[i] == 'E')
			put_door(mlx);
		if (join[i] == '\n')
			plus_a_l(mlx);
		if (join[i++] != '\n')
			mlx->ancho = mlx->ancho + 50;
	}
	return ;
}
void	leaks(void)
{
	system("leaks so_long");
}

int	main(int arg, char **args)
{
	t_data	mlx;

//	atexit(leaks);
	mlx.mlx = mlx_init();
	if (arg != 2)
		return (0);
	mlx.join = save_map(args[1]);
	if (mlx.join == NULL || check_muros(mlx.join) == 0
		|| check_player(mlx.join) == 0 || check_door(mlx.join) == 0
		|| check_coin(mlx.join) == 1 || check_square(mlx.join) == 0)
		return (an_error(&mlx));
	draw_map(&mlx, mlx.join);
	mlx.moves = 0;
	mlx.ncoins = n_coins(&mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_and_free, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
