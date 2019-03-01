/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:48:35 by spuisais          #+#    #+#             */
/*   Updated: 2019/03/01 17:33:23 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH  1800
# define HEIGHT 1600
# define W_DIV1 32
# define W_DIV2 2.3
# define H_DIV	25
# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			offset;
	t_point			map_size;
	t_point			s;
	t_point			size;
	int				**tab;
	int				v;
	float			v_m;
	void			*image;
	char			*pxl;
	int				bpp;
	int				line_size;
	int				endian;
	int				view;
}					t_env;

void	ft_bresenham(t_env *env, t_point a, t_point b, int color);
void	create_grid(t_env *env);
void	create_iso_grid(t_env *env);
void	move_map(int key, t_env *env);
void	ft_zoom(int key, t_env *env);
void	change_height(int key, t_env *env);
void	ft_pixel_put(t_env *env, t_point pos, int color);
void	init_hud(t_env *env);
int		ft_deal_mouse(int button, int x, int y, void *param);
int		ft_deal_key(int key, void *param);
int		get_map_size(char **map);
int		pick_color(int height1, int height2);

#endif
