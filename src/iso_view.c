/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:01:32 by spuisais          #+#    #+#             */
/*   Updated: 2019/03/01 18:01:14 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_iso_line(t_env *env, t_point start, t_point coor, char dir)
{
	t_point	next;
	int		color;
	int		height1;
	int		height2;

	next.y = start.y + env->size.y + env->v;
	height1 = env->tab[coor.y][coor.x - 1];
	if (dir == 'y')
		height2 = env->tab[coor.y + 1][coor.x - 1];
	else if (dir == 'x')
		height2 = env->tab[coor.y][coor.x];
	else
		return ((void)NULL);
	if (dir == 'y')
		next.x = start.x - env->size.x;
	else if (dir == 'x')
		next.x = start.x + env->size.x;
	color = pick_color(height1, height2);
	ft_bresenham(env, start, next, color);
}

void	create_iso_grid(t_env *env)
{
	t_point	s;
	t_point	p;

	p.y = 0;
	while (p.y < env->map_size.y)
	{
		p.x = 0;
		while (p.x < env->map_size.x)
		{
			s.y = (((p.x + p.y) * env->size.y - (env->tab[p.y][p.x] * env->v_m))
					+ env->s.y);
			s.x = ((p.x++ - p.y) * env->size.x) + env->s.x;
			env->v = (env->tab[p.y][p.x - 1] - env->tab[p.y][p.x]) * env->v_m;
			if (p.x < env->map_size.x)
				draw_iso_line(env, s, p, 'x');
			if (p.y < env->map_size.y - 1)
				env->v = (env->tab[p.y][p.x - 1] - env->tab[p.y + 1][p.x - 1])
				* env->v_m;
			if (p.y < env->map_size.y - 1)
				draw_iso_line(env, s, p, 'y');
		}
		s.y += env->size.y;
		p.y++;
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->image, 0, 0);
	init_hud(env);
}
