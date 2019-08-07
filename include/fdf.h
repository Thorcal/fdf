/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:48:35 by spuisais          #+#    #+#             */
/*   Updated: 2019/04/01 15:52:32 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W_DIV1 32
# define W_DIV2 2.3
# define H_DIV	25
# include "mlx.h"
# include "/System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

typedef	struct		s_fpoint
{
	float			x;
	float			y;
}					t_fpoint;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_env
{
	int				width;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	t_point			offset;
	t_point			map_size;
	t_point			s;
	t_fpoint		size;
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

void				ft_bresenham(t_env *env, t_point a, t_point b, int color);
void				create_grid(t_env *env);
void				create_iso_grid(t_env *env);
void				move_map(int key, t_env *env);
void				ft_zoom(int key, t_env *env);
void				change_height(int key, t_env *env);
void				ft_pixel_put(t_env *env, t_point pos, int color);
void				init_hud(t_env *env);
void				free_stuff(char **map, char ***tmp, char **line, int size);
void				screen_size(t_env *env);
void				reset_offset(t_env *env);
void				loop_num(char ***tmp, int *i);
void				check_line(char *line);
void				ft_exit();
int					red_cross(t_env *env);
int					ft_deal_mouse(int button, int x, int y, void *param);
int					ft_deal_key(int key, void *param);
int					get_map_size(char **map);
int					pick_color(int height1, int height2);
int					compare_and_close(int i, int j, int fd);
int					set_null_and_free(t_env *env);
int					secure_dup_and_split(char **line, char **map, char ***tmp);
int					check_chars(int fd, char **line, char **map, char ***tmp);

#endif
