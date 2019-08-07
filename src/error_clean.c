/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:32:43 by spuisais          #+#    #+#             */
/*   Updated: 2019/04/01 13:26:02 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/get_next_line.h"

void	ft_exit(void)
{
	ft_putendl("Error, leaving program now.");
	exit(0);
}

int		set_null_and_free(t_env *env)
{
	env->tab = NULL;
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->image = NULL;
	env->pxl = NULL;
	free(env->tab);
	free(env->mlx_ptr);
	free(env->win_ptr);
	free(env->image);
	free(env->pxl);
	return (-1);
}

int		secure_dup_and_split(char **line, char **map, char ***tmp)
{
	if (!(*map = ft_strdup(*line)))
		return (-1);
	if (!(*tmp = ft_strsplit(*map, ' ')))
		return (-1);
	return (0);
}

void	loop_num(char ***tmp, int *i)
{
	while ((*tmp)[*i])
		(*i)++;
}

void	check_line(char *line)
{
	int p;

	p = -1;
	while (line[++p] != '\0')
		if (!(ft_isdigit(line[p])) && line[p] != ' ' && line[p] != '-')
			ft_exit();
}
