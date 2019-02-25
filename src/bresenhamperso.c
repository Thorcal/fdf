/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:40:41 by spuisais          #+#    #+#             */
/*   Updated: 2019/02/25 15:44:01 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	trace_line(t_env env, t_point point1, t_point point2)
{
	t_point	delta;
	int		e;

	delta.x = point2.x - point1.x;
	delta.y = point2.y - point1.y;
	if (delta.x != 0)
	{
		if (delta.x > 0)
		{
			if (delta.y != 0)
			{
				if (delta.y > 0)
				{
					if (delta.x >= delta.y)
					{
						e = delta.x;
						delta.x = e * 2;
						delta.y *= 2;
						while (point1.x++ != point2.x)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e -= delta.y) < 0)
							{
								point1.y++;
								e += delta.x;
							}
						}
					}
					else
					{
						e = delta.y;
						delta.y = e * 2;
						delta.x *= 2;
						while (point1.y++ != point2.y)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e -= delta.x) < 0)
							{
								point1.x++;
								e += delta.y;
							}
						}
					}
				}
				else if (delta.y < 0)
				{
					if (delta.x >= -delta.y)
					{
						e = delta.x;
						delta.x = e * 2;
						delta.y *= 2;
						while (point1.x++ != point2.x)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e += delta.y) < 0)
							{
								point1.y--;
								e += delta.x;
							}
						}
					}
					else
					{
						e = delta.y;
						delta.y = e * 2;
						delta.x *= 2;
						while (point1.y-- != point2.y)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e += delta.x) > 0)
							{
								point1.x++;
								e += delta.y;
							}
						}
					}
				}
			}
			else if (delta.y == 0)
				while (point1.x++ != point2.x)
					mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
		}
		if (delta.x < 0)
		{
			if ((delta.y = point2.y - point1.y) != 0)
			{
				if (delta.y > 0)
				{
					if (-delta.x >= delta.y)
					{
						e = delta.x;
						delta.x = e * 2;
						delta.y *= 2;
						while (point1.x-- != point2.x)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e += delta.y) >= 0)
							{
								point1.y++;
								e += delta.x;
							}
						}
					}
					else
					{
						e = delta.y;
						delta.y = e * 2;
						delta.x *= 2;
						while (point1.y++ != point2.y)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e += delta.x) <= 0)
							{
								point1.x--;
								e += delta.y;
							}
						}
					}
				}
				else if (delta.y < 0)
				{
					if (delta.x <= delta.y)
					{
						e = delta.x;
						delta.x = e * 2;
						delta.y *= 2;
						while (point1.x-- != point2.x)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e -= delta.y) >= 0)
							{
								point1.y--;
								e += delta.x;
							}
						}
					}
					else
					{
						e = delta.y;
						delta.y = e * 2;
						delta.x *= 2;
						while (point1.y-- != point2.y)
						{
							mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
							if ((e -= delta.x) >= 0)
							{
								point1.x--;
								e += delta.y;
							}
						}
					}
				}
				else if (delta.y == 0)
					while (point1.x-- != point2.x)
						mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
			}
		}
	}
	else if (delta.x == 0)
	{
		if ((delta.y = point2.y - point1.y) != 0)
		{
			if (delta.y > 0)
			{
				while (point1.y++ != point2.y)
				{
					mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
				}
			}
			else if (delta.y < 0)
				while (point1.y-- != point2.y)
					mlx_pixel_put(env.mlx_ptr, env.win_ptr, point1.x, point1.y, 0xFF0000);
		}
	}
}
