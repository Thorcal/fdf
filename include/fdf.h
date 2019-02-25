/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:48:35 by spuisais          #+#    #+#             */
/*   Updated: 2019/02/25 16:00:11 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH  800
# define HEIGHT 600
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
	int				**array;
}					t_env;

void	ft_bresenham(t_env env, t_point a, t_point b, int color);

#endif
