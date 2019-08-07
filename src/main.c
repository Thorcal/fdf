/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:24:00 by spuisais          #+#    #+#             */
/*   Updated: 2019/04/01 16:07:15 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/get_next_line.h"
#include <stdlib.h>

int		check_error(int fd)
{
	char	*line;
	char	*map;
	char	**tmp;
	t_point	p;

	p.x = 0;
	if (check_chars(fd, &line, &map, &tmp) == -1)
		return (-1);
	loop_num(&tmp, &p.x);
	free_stuff(&map, &tmp, &line, p.x);
	while (get_next_line(fd, &line) > 0)
	{
		check_line(line);
		p.y = 0;
		if (secure_dup_and_split(&line, &map, &tmp) == -1)
			return (-1);
		loop_num(&tmp, &p.y);
		free_stuff(&map, &tmp, &line, p.x);
		if (compare_and_close(p.x, p.y, fd) == -1)
			return (-1);
	}
	free(line);
	return (0);
}

void	ft_pixel_put(t_env *env, t_point pos, int color)
{
	int i;

	if (!(pos.x <= env->width && pos.x >= 0 &&
				pos.y <= env->height && pos.y >= 0))
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

	i = -1;
	array = NULL;
	if (!(array = (int**)malloc(sizeof(int*) * env->map_size.y)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		j = -1;
		map = ft_strdup(line);
		tmp = ft_strsplit(map, ' ');
		env->map_size.x = get_map_size(tmp);
		if (!(array[++i] = (int*)malloc(sizeof(int) * env->map_size.x)))
			return (NULL);
		while (tmp[++j] != '\0')
			array[i][j] = ft_atoi(tmp[j]);
		free_stuff(&map, &tmp, &line, env->map_size.x);
	}
	free(line);
	return (array);
}

void	init_variables(t_env *env, int fd, char *argv_1)
{
	char	*line;

	env->map_size.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		env->map_size.y++;
		free(line);
	}
	free(line);
	close(fd);
	fd = open(argv_1, O_RDONLY);
	if (!(env->tab = create_array(fd, env, line)))
		ft_exit();
	env->view = 0;
	screen_size(env);
	env->v_m = 1.00;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width,
			env->height, argv_1);
	env->image = mlx_new_image(env->mlx_ptr, env->width, env->height);
	env->pxl = mlx_get_data_addr(env->image, &env->bpp,
			&env->line_size, &env->endian);
}

int		main(int argc, char *argv[])
{
	t_env	env;
	int		fd;
	int		i;

	i = 0;
	if (argc != 2 || !argv[1])
		ft_exit();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit();
	if (check_error(fd) == -1)
		ft_exit();
	close(fd);
	fd = open(argv[1], O_RDONLY);
	init_variables(&env, fd, argv[1]);
	create_grid(&env);
	mlx_hook(env.win_ptr, 2, 0, ft_deal_key, &env);
	mlx_hook(env.win_ptr, 17, 0, red_cross, &env);
	mlx_mouse_hook(env.win_ptr, ft_deal_mouse, (void*)&env);
	mlx_loop(env.mlx_ptr);
	i = 0;
	while (i <= env.map_size.x)
		free(env.tab[i++]);
	free(env.tab);
	return (0);
}
