/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:10:18 by spuisais          #+#    #+#             */
/*   Updated: 2019/03/01 17:49:49 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		get_map_size(char **map)
{
	int	x;

	x = 0;
	while (map[x] != '\0')
		x++;
	return (x);
}

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
}

int		pick_color(int height1, int height2)
{
	int	color;

	if (height1 <= 0 && height2 <= 0)
		color = 0x5a8ee2;
	else if (height1 <= 10 && height2 <= 10)
		color = 0x78e25a;
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
