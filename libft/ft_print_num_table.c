/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:01:51 by spuisais          #+#    #+#             */
/*   Updated: 2019/02/19 14:13:56 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_num_table(int **tab, int size_x, int size_y)
{
	int			i;
	int			j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
