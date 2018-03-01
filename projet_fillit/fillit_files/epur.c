/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:16:26 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/15 21:47:08 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	epur_one_piece(char **one_piece)
{
	ssize_t	i;
	ssize_t	j;
	int		temoin;

	i = 3;
	while (i >= 0)
	{
		temoin = 0;
		j = 3;
		while (j >= 0 && temoin == 0)
		{
			if (*(*(one_piece + i) + j) == '.')
				*(*(one_piece + i) + j) = '\0';
			else
				temoin = 1;
			j--;
		}
		if (temoin == 0)
		{
			free(*(one_piece + i));
			*(one_piece + i) = NULL;
		}
		i--;
	}
}

void	epur_pieces(char ***pieces)
{
	size_t	i;

	i = 0;
	while (*(pieces + i) != NULL)
	{
		epur_one_piece(*(pieces + i));
		i++;
	}
}
