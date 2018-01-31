/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:13:01 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 15:32:36 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tetrimino(char **one_piece)
{
	ssize_t	i;
	ssize_t	j;
	size_t	count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*(*(one_piece + i) + j) != '.')
			{
				count++;
				if (!((i - 1 >= 0 && *(*(one_piece + (i - 1)) + j) != '.')
					|| (i + 1 < 4 && *(*(one_piece + (i + 1)) + j) != '.')
					|| (j - 1 >= 0 && *(*(one_piece + i) + (j - 1)) != '.')
					|| (j + 1 < 4 && *(*(one_piece + i) + (j + 1)) != '.')))
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (count == 4 ? 1 : 0);
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
