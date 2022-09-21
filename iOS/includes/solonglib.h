/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:40:09 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 12:53:46 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONGLIB_H
# define SOLONGLIB_H
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>

typedef struct s_data{
	void	*mlx;
	void	*win;
	char	*join;
	int		img_ancho;
	int		img_alto;
	int		moves;
	int		ancho;
	int		largo;
	int		ncoins;
	int		k;
	int		col;
}	t_data;
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int		lens(const char *s);
int		find_nl(char *s);
char	*join(char *sol, char *buff);
char	*lecture(char *buff, int fd, int BUFFER_SIZE);
char	*the_line(char *buff);
char	*next_line(char *buff);
char	*save_map(char *s);
int		check_muros(char *join);
int		key_hook(int keycode, t_data *mlx);
void	put_wall(t_data *mlx);
void	put_floor(t_data *mlx);
void	put_coin(t_data *mlx);
void	put_personaje(t_data *mlx);
void	put_door(t_data *mlx);
void	put_open_door(t_data *mlx);
void	draw_map(t_data *mlx, char *join);
int		move_right(t_data *mlx);
int		*ft_pos(char *join);
int		ft_ancho(char *join);
int		alto(char *join);
int		move_left(t_data *mlx);
int		map_weidth(t_data *mlx);
int		map_long(t_data *mlx);
int		n_coins(t_data *mlx);
void	ft_putnbr_fd(int n, int fd);
void	put_moves(t_data *mlx);
int		exit_and_free(t_data *mlx);
int		handle_door(t_data *mlx);
int		*handle_moves(t_data *mlx);
int		map_weidth(t_data *mlx);
int		map_long(t_data *mlx);
int		n_coins(t_data *mlx);
void	handle_coins(t_data *mlx);
int		check_wall_largo_up(t_data *mlx);
int		check_wall_largo_down(t_data *mlx);
void	close_win(t_data *mlx);
int		check_wall_ancho_right(t_data *mlx);
int		check_wall_ancho_left(t_data *mlx);
int		*ft_pos(char *join);
int		handle_door(t_data *mlx);
void	put_moves(t_data *mlx);
int		key_hook(int keycode, t_data *mlx);
int		move_right(t_data *mlx);
int		move_left(t_data *mlx);
int		move_up(t_data *mlx);
int		move_down(t_data *mlx);
void	put_floor_hero(t_data *mlx);
void	put_floor_coin(t_data *mlx);
void	plus_a_l(t_data *mlx);
int		an_error(t_data *mlx);
int		check_player(char *join);
char	*save_map_util(char *join);
int		jumpy(char *join);
int		check_player(char *join);
int		check_door(char *join);
int		check_coin(char *join);
int		check_square(char *join);

#endif
