/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:44:56 by spuisais          #+#    #+#             */
/*   Updated: 2019/03/19 15:08:32 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			compare_and_close(int i, int j, int fd)
{
	if (i != j)
	{
		close(fd);
		return (-1);
	}
	return (0);
}

static int	ft_abs(int i)
{
	i < 0 ? i *= -1 : (0);
	return (i);
}

static void	ft_horizontal(t_point a, t_point b, t_env *env, int color)
{
	int xinc;
	int yinc;
	int cumul;
	int i;

	xinc = (b.x > 0) ? 1 : -1;
	yinc = (b.y > 0) ? 1 : -1;
	b.x = ft_abs(b.x);
	b.y = ft_abs(b.y);
	cumul = b.y / 2;
	i = 0;
	while (i <= b.y)
	{
		if ((a.x >= 0 && a.x < env->width) && (a.y >= 0 && a.y < env->height))
			ft_pixel_put(env, a, color);
		cumul += b.x;
		if (cumul >= b.y)
		{
			cumul -= b.y;
			a.x += xinc;
		}
		a.y += yinc;
		i++;
	}
}

static void	ft_vertical(t_point a, t_point b, t_env *env, int color)
{
	int xinc;
	int yinc;
	int cumul;
	int i;

	xinc = (b.x > 0) ? 1 : -1;
	yinc = (b.y > 0) ? 1 : -1;
	b.x = ft_abs(b.x);
	b.y = ft_abs(b.y);
	cumul = b.x / 2;
	i = 0;
	while (i <= b.x)
	{
		if ((a.x >= 0 && a.x < env->width) && (a.y >= 0 && a.y < env->height))
			ft_pixel_put(env, a, color);
		cumul += b.y;
		if (cumul >= b.x)
		{
			cumul -= b.x;
			a.y += yinc;
		}
		a.x += xinc;
		i++;
	}
}

void		ft_bresenham(t_env *env, t_point a, t_point b, int color)
{
	b.x = b.x - a.x;
	b.y = b.y - a.y;
	if (ft_abs(b.x) > ft_abs(b.y))
		ft_vertical(a, b, env, color);
	else
		ft_horizontal(a, b, env, color);
}
