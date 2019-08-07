/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:40:01 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/23 14:57:09 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_hud(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 5, 0xFFFFFF, "Esc            : Quit");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 20, 0xFFFFFF, "WASD/Arrow Keys: Move");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 35, 0xFFFFFF, "Scroll up/+    : Zoom in");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 50, 0xFFFFFF, "Scroll down/-  : Zoom out");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 65, 0xFFFFFF, "1/2            : Change Height");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 80, 0xFFFFFF, "I              : Isometric view");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 95, 0xFFFFFF, "P              : Parallel view");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			5, 110, 0xFFFFFF, "SPACE          : Center");
}

void	screen_size(t_env *env)
{
	env->width = env->map_size.x * 10 + 50;
	if (env->width < 600)
		env->width = 600;
	if (env->width > 2560)
		env->width = 2560;
	env->size.x = env->width / env->map_size.x;
	env->size.y = env->size.x / 2;
	env->height = env->map_size.y * env->size.x;
	if (env->height > 1390)
		env->height = 1390;
	env->s.x = (env->width / 2 -
			((env->map_size.x * env->size.x) / 2)) - env->size.y;
	env->s.y = env->height / 2 - (env->map_size.y * env->size.y) + env->size.y;
}

void	reset_offset(t_env *env)
{
	env->s.x = (env->width / 2 - (env->map_size.x * env->size.x) / 2)
		- env->size.y;
	env->s.y = (env->height / 2 - (env->map_size.y * env->size.y)
		+ env->size.y);
	if (env->view == 1)
	{
		env->s.x = (env->width / 2);
		env->s.y = (env->height / 2) - (env->map_size.y * env->size.y);
	}
	ft_bzero(env->pxl, env->line_size * env->height);
	if (env->view == 0)
		create_grid(env);
	else
		create_iso_grid(env);
}
