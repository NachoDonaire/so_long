/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:30:37 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 14:21:08 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solonglib.h"

int	*ft_pos(char *join)
{
	int	i;
	int	k;
	int	count;
	int	*sol;

	sol = malloc(sizeof(int) * 2);
	i = 0;
	k = 0;
	count = 0;
	while (join[i] != 'P')
	{
		if (join[i] == '\n')
		{
			count++;
			k = 0;
		}
		k++;
		i++;
	}
	count = count * 50;
	sol[0] = (k - 1) * 50;
	sol[1] = count;
	return (sol);
}

int	handle_door(t_data *mlx)
{
	put_door(mlx);
	return (0);
}

void	put_moves(t_data *mlx)
{
	ft_putnbr_fd(mlx->moves, 1);
	mlx->moves += 0.5;
	write(1, "\n", 1);
}

int	key_hook(int keycode, t_data *mlx)
{
	if (keycode == '|' || keycode == 2 || keycode == 65363 || keycode == 100)
		move_right(mlx);
	else if (keycode == 123 || keycode == 0 || keycode == 65361 || keycode == 97)
		move_left(mlx);
	else if (keycode == '}' || keycode == 1 || keycode == 65364 || keycode == 115)
		move_down(mlx);
	else if (keycode == '~' || keycode == 13 || keycode == 65362 || keycode == 119)
		move_up(mlx);
		else if (keycode == '5' || keycode == 65307)
		exit_and_free(mlx);
	if (mlx->ncoins <= 0)
		put_open_door(mlx);
	close_win(mlx);
	return (0);
}
