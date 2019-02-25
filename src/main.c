/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:24:00 by spuisais          #+#    #+#             */
/*   Updated: 2019/02/25 16:51:07 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	test(t_env env, t_point origin, t_point dest)
{
	t_point delta;
	double	error;
	int		delta_error;
	int		y;
	int		x;

	delta.x = dest.x - origin.x;
	delta.y = dest.y - origin.y;
	error = 0;
	delta_error = fabs((double)delta.y / (double)delta.x);
	y = origin.y;
	x = origin.x;
	while (x++ < dest.x)
	{
		mlx_pixel_put(env.mlx_ptr, env.win_ptr, x, y, 0xFF0000);
		error = error + delta_error;
		if (error >= 0.5)
		{
			++y;
			error -= 1.0;
		}
	}
}

int		get_map_size(char **map)
{
	int			x;

	x = 0;
	while (map[x] != '\0')
		x++;
	return (x);
}

void	init_hud(t_env env)
{
	int		color;
	t_point	start;
	t_point	end;

	color = 0x59b0db;
	start.x = 0;
	start.y = 0;
	end.x = WIDTH;
	end.y = 0;
	while (end.y < 200)
	{
		ft_bresenham(env, start, end, 0xFFFFFF);
		start.y++;
		end.y++;
	}
	mlx_string_put(env.mlx_ptr, env.win_ptr, WIDTH / W_DIV1, HEIGHT / H_DIV, 0xFFFFFF, "Esc: Quit");
	mlx_string_put(env.mlx_ptr, env.win_ptr, WIDTH / W_DIV2, HEIGHT / H_DIV, 0xFFFFFF, "FdF by Steven");
}

int		ft_deal_key(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	//printf("Keycode of pressed key = %d\n", key);
	if (key == 53)
	{
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0);
	}
	return (0);
}

void	draw_line(t_env env, t_point start, char dir)
{
	t_point next;

	if (dir == 'y')
	{
		next.x = start.x;
		next.y = start.y + env.offset.y;
		if (next.y < HEIGHT)
			ft_bresenham(env, start, next, 0xFFFFFF);
	}
	else if (dir == 'x')
	{
		next.x = start.x + env.offset.x;
		next.y = start.y;
		if (next.x < WIDTH)
			ft_bresenham(env, start, next, 0xFFFFFF);
	}
}

void	create_grid(t_env env)
{
	int		i;
	int		j;
	t_point start;

	i = 0;
	start.y = env.offset.y / 2;
	while (i < env.map_size.y)
	{
		j = 0;
		start.x = 0 - (env.offset.x / 2);
		while (j < env.map_size.x)
		{
			start.x += env.offset.x;
			draw_line(env, start, 'y');
			if (!(ft_isdigit(env.array[i][j])))
				mlx_pixel_put(env.mlx_ptr, env.win_ptr, start.x, start.y, 0xFFFFFF);
			j++;
			draw_line(env, start, 'x');
		}
		start.y += env.offset.y;
		i++;
	}
}

void	create_iso_grid(t_env env)
{
	int		i;
	int		j;
	t_point start;
	t_point	pos;

	i = 0;
	start.y = env.offset.y / 2;
	while (i < env.map_size.y)
	{
		j = 0;
		pos.y = i;
		start.x = 0 - (env.offset.x / 2);
		while (j < env.map_size.x)
		{
			pos.x = j;
			start.x = (pos.x - pos.y) * (20 / 2) + (WIDTH / 2);
			start.y = (pos.x + pos.y) * (20 / 2) + env.offset.y;
			/*printf("start.x = (%d - %d) * (%d / 2)\n", j, i, env.offset.x);
			printf("start.x = (%d) * (%d)\n", j - i, env.offset.x / 2);
			printf("start.x = %d\n", (j - i) * (env.offset.x / 2));
			printf("start.y = (%d + %d) * (%d / 2)\n", j, i, env.offset.y);
			printf("start.y = (%d) * (%d)\n", j + i, env.offset.y / 2);
			printf("start.y = %d\n", (j + i) * (env.offset.y / 2));
			sleep(1);*/
			draw_line(env, start, 'y');
			if (!(ft_isdigit(env.array[i][j])))
				mlx_pixel_put(env.mlx_ptr, env.win_ptr, start.x, start.y, 0xFFFFFF);
			j++;
			draw_line(env, start, 'x');
		}
		start.y += env.offset.y;
		i++;
	}
}

int		**create_array(int fd, t_env *env, char *line)
{
	char	*map;
	char	**tmp;
	int		**array;
	int		i;
	int		j;

	i = 0;
	array = NULL;
	if (!(array = (int**)malloc(sizeof(int*) * env->map_size.y)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		map = ft_strdup(line);
		tmp = ft_strsplit(map, ' ');
		env->map_size.x = get_map_size(tmp);
		if (!(array[i] = (int*)malloc(sizeof(int) * env->map_size.x)))
			return (NULL);
		while (tmp[++j] != '\0')
			array[i][j] = ft_atoi(tmp[j]);
		i++;
		free(line);
	}
	return (array);
}

void	init_variables(t_env *env, int fd, char *argv_1)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(argv_1, O_RDONLY);
	env->map_size.y = i;
	env->array = create_array(fd, env, line);
	env->offset.x = WIDTH / env->map_size.x;
	env->offset.y = HEIGHT / env->map_size.y;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "FdF Steven");
}

int		main(int argc, char *argv[])
{
	t_env	env;
	int		fd;

	if (argc != 2 || !argv[1])
		return (-1);
	fd = open(argv[1], O_RDONLY);
	init_variables(&env, fd, argv[1]);
	//init_hud(env);
	create_grid(env);
	mlx_key_hook(env.win_ptr, ft_deal_key, (void*)&env);
	mlx_loop(env.mlx_ptr);
}
