/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:27:57 by spuisais          #+#    #+#             */
/*   Updated: 2019/07/22 14:54:06 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	change_height(int key, t_env *env)
{
	if (key == 83)
		env->v_m += 0.10;
	if (key == 84)
		env->v_m -= 0.10;
	ft_bzero(env->pxl, env->line_size * env->height);
	if (env->view == 0)
		create_grid(env);
	else
		create_iso_grid(env);
}

void	ft_zoom(int key, t_env *env)
{
	float mult;

	mult = env->v_m / env->size.x;
	if ((key == 69 || key == -15) && env->size.x >= 1)
	{
		env->v_m += mult;
		env->size.x += 1;
	}
	else if ((key == 78 || key == -14) && env->size.x > 1)
	{
		env->v_m -= mult;
		env->size.x -= 1;
	}
	env->size.y = env->size.x / 2;
	reset_offset(env);
}

void	move_map(int key, t_env *env)
{
	if (key == 123 || key == 0)
		env->s.x += 10;
	else if (key == 124 || key == 2)
		env->s.x -= 10;
	else if (key == 126 || key == 13)
		env->s.y += 10;
	else if (key == 125 || key == 1)
		env->s.y -= 10;
	ft_bzero(env->pxl, env->line_size * env->height);
	if (env->view == 0)
		create_grid(env);
	else
		create_iso_grid(env);
}

int		ft_deal_mouse(int button, int x, int y, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	x = 0;
	y = 0;
	if (button == 4)
		ft_zoom(-15, env);
	else if (button == 5)
		ft_zoom(-14, env);
	return (0);
}

int		ft_deal_key(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == 49)
		reset_offset(env);
	if (key == 53)
		red_cross(env);
	if (key == 34 || key == 35)
		ft_bzero(env->pxl, env->line_size * env->height);
	if (key == 35)
		env->view = 0;
	else if (key == 34)
		env->view = 1;
	if (key == 35 || key == 34)
		reset_offset(env);
	else if ((key >= 0 && key <= 2) || key == 13 || (key >= 123 && key <= 126))
		move_map(key, env);
	else if (key == 69 || key == 78)
		ft_zoom(key, env);
	else if (key == 83 || key == 84)
		change_height(key, env);
	return (0);
}
