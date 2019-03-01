/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:24:00 by spuisais          #+#    #+#             */
/*   Updated: 2019/03/01 17:40:56 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_pixel_put(t_env *env, t_point pos, int color)
{
	int i;

	if (!(pos.x <= WIDTH && pos.x >= 0 && pos.y <= HEIGHT && pos.y >= 0))
		return ((void)NULL);
	i = env->line_size * pos.y + (pos.x * (env->bpp / 8));
	env->pxl[i] = (char)color;
	env->pxl[i + 1] = (char)(color >> 8);
	env->pxl[i + 2] = (char)(color >> 16);
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
	env->tab = create_array(fd, env, line);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "FdF Steven");
	env->view = 0;
	env->size.x = 20;
	env->size.y = env->size.x / 2;
	env->s.x = WIDTH / 2 - (WIDTH / (env->map_size.x / 2));
	env->s.y = HEIGHT / 2 - (HEIGHT / (env->map_size.y / 2));
	env->v_m = 1.00;
	env->image = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT);
	env->pxl = mlx_get_data_addr(env->image, &env->bpp,
			&env->line_size, &env->endian);
}

int		main(int argc, char *argv[])
{
	t_env	env;
	int		fd;

	if (argc != 2 || !argv[1])
		return (-1);
	fd = open(argv[1], O_RDONLY);
	init_variables(&env, fd, argv[1]);
	create_grid(&env);
	init_hud(&env);
	mlx_key_hook(env.win_ptr, ft_deal_key, (void*)&env);
	mlx_mouse_hook(env.win_ptr, ft_deal_mouse, (void*)&env);
	mlx_loop(env.mlx_ptr);
}
