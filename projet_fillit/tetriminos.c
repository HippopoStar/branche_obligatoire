/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:13:01 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 16:03:59 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetrimino(char **one_piece)
{
	ssize_t	i;
	ssize_t	j;
	size_t	count_sharp_mark;
	size_t	count_bonds;

	count_sharp_mark = 0;
	count_bonds = 0;
	i = -1;
	while (++i < 4 && (j = -1) != 0)
		while (++j < 4)
			if (*(*(one_piece + i) + j) != '.')
			{
				count_sharp_mark++;
				if (i - 1 >= 0 && *(*(one_piece + (i - 1)) + j) != '.')
					count_bonds++;
				if (i + 1 < 4 && *(*(one_piece + (i + 1)) + j) != '.')
					count_bonds++;
				if (j - 1 >= 0 && *(*(one_piece + i) + (j - 1)) != '.')
					count_bonds++;
				if (j + 1 < 4 && *(*(one_piece + i) + (j + 1)) != '.')
					count_bonds++;
			}
	return ((count_sharp_mark == 4 && !(count_bonds < 6)) ? 1 : 0);
}

int		tetriminos(char ***pieces)
{
	size_t	i;

	i = 0;
	while (*(pieces + i) != NULL)
	{
		if (!(tetrimino(*(pieces + i))))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
