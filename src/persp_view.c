/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:01:44 by spuisais          #+#    #+#             */
/*   Updated: 2019/03/01 17:50:17 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

static void	draw_line(t_env *env, t_point start, t_point coor, char dir)
{
	t_point	next;
	int		color;
	int		height1;
	int		height2;

	height1 = env->tab[coor.y][coor.x - 1];
	if (dir == 'y')
	{
		height2 = env->tab[coor.y + 1][coor.x - 1];
		next.x = start.x;
		next.y = start.y + env->size.x;
	}
	else if (dir == 'x')
	{
		height2 = env->tab[coor.y][coor.x];
		next.x = start.x + env->size.x;
		next.y = start.y;
	}
	else
		return ((void)NULL);
	color = pick_color(height1, height2);
	ft_bresenham(env, start, next, color);
}

void		create_grid(t_env *env)
{
	t_point start;
	t_point coor;

	coor.y = 0;
	start.y = env->s.y;
	while (coor.y < env->map_size.y)
	{
		coor.x = 0;
		start.x = env->s.x;
		while (coor.x < env->map_size.x)
		{
			start.x += env->size.x;
			coor.x++;
			if (coor.x < env->map_size.x)
				draw_line(env, start, coor, 'x');
			if (coor.y < env->map_size.y - 1)
				draw_line(env, start, coor, 'y');
		}
		coor.y++;
		start.y += env->size.x;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->image, 0, 0);
	init_hud(env);
}
