/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:10:18 by spuisais          #+#    #+#             */
/*   Updated: 2019/04/01 14:41:19 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/get_next_line.h"

void	free_stuff(char **map, char ***tmp, char **line, int size)
{
	int i;

	i = 0;
	if (*line)
		free(*line);
	if (*map)
		free(*map);
	if (*tmp)
	{
		while (i < size)
			free((*tmp)[i++]);
		free(*tmp);
	}
}

int		get_map_size(char **map)
{
	int	x;

	x = 0;
	while (map[x] != '\0')
		x++;
	return (x);
}

int		pick_color(int height1, int height2)
{
	int	color;

	if (height1 <= 0 && height2 <= 0)
		color = 0x5a8ee2;
	else if (height1 <= 10 && height2 <= 10)
		color = 0x84e866;
	else if (height1 <= 20 && height2 <= 20)
		color = 0xf2ca48;
	else if (height1 <= 30 && height2 <= 30)
		color = 0xe58639;
	else if (height1 <= 40 && height2 <= 40)
		color = 0xaa6e38;
	else if (height1 <= 50 && height2 <= 50)
		color = 0x5e422a;
	else if (height1 <= 70 && height2 <= 70)
		color = 0x3d2a1b;
	else if (height1 <= 120 && height2 <= 120)
		color = 0x332c28;
	else
		color = 0xFFFFFF;
	return (color);
}

int		red_cross(t_env *env)
{
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
}

int		check_chars(int fd, char **line, char **map, char ***tmp)
{
	if (!(get_next_line(fd, line) > 0))
		return (-1);
	check_line(*line);
	if (secure_dup_and_split(line, map, tmp) == -1)
		return (-1);
	return (0);
}
