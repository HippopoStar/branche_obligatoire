/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:12:06 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/02 15:38:11 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	decal(char **one_piece, size_t top, size_t left)
{
	size_t	i;
	size_t	j;
	char	character;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			character = *(*(one_piece + i) + j);
			if ('A' <= character && character <= 'Z')
			{
				*(*(one_piece + (i - top)) + (j - left)) = character;
				*(*(one_piece + i) + j) = '.';
			}
			j++;
		}
		i++;
	}
}

void	top_left_corner_one_piece(char **one_piece)
{
	int		i;
	int		j;
	int		top;
	int		left;

	top = 4;
	left = 4;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ('A' <= *(*(one_piece + i) + j) &&\
					*(*(one_piece + i) + j) <= 'Z')
			{
				if (i < top)
					top = i;
				if (j < left)
					left = j;
			}
		}
	}
	if (top || left)
		decal(one_piece, top, left);
}

void	top_left_corner_pieces(char ***pieces)
{
	size_t	i;

	i = 0;
	while (*(pieces + i) != NULL)
	{
		top_left_corner_one_piece(*(pieces + i));
		i++;
	}
}
