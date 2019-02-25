/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_table.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:20:22 by spuisais          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:20 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_table(char **tab)
{
	int			x;

	x = 0;
	while (tab[x] != '\0')
	{
		ft_putstr(tab[x]);
		ft_putchar(' ');
		x++;
	}
	ft_putchar('\n');
}
