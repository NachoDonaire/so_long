/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:03:17 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 13:35:51 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "solonglib.h"

int	an_error(t_data *mlx)
{
	write(1, "Error:\n", 7);
	write(1, "something went wrong", 20);
	free(mlx->join);
	return (0);
}

char	*save_map(char *s)
{
	int		fd;
	char	*buff;
	char	*join;
	char	*tmp;

	fd = open(s, O_RDONLY);
	join = malloc(sizeof(char *) * 2);
	join[0] = '\0';
	buff = get_next_line(fd);
	while (buff != NULL)
	{
		if (buff)
		{
			tmp = join;
			join = ft_strjoin(join, buff);
			free(buff);
			free(tmp);
		}
		buff = get_next_line(fd);
	}
	close(fd);
	join = save_map_util(join);
	return (join);
}

int	check_muros(char *join)
{
	int	i;
	int	jump;
	int	count;

	jump = jumpy(join);
	count = 0;
	i = 0;
	while (join[i])
	{
		if (join[i] == '\n')
			count++;
		if (count == 0 && join[i] != '1')
			return (0);
		if (join[i] == '\n' && count != 0
			&& count != jump && (join[i + 1] != '1'
				|| join[i - 1] != '1'))
			return (0);
		if (count == jump - 1 && join[i] != '1' && join[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
