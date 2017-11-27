/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_pieces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 23:39:22 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/27 23:54:39 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_line(char *line)
{
	size_t	column_nb;

	column_nb = 0;
	while (*(line + column_nb) != '\0')
	{
		write(1, &(*(line + column_nb)), 1);
		column_nb++;
	}
}

void	show_one_piece(char **one_piece)
{
	size_t	line_nb;

	line_nb = 0;
	while (*(one_piece + line_nb) != NULL)
	{
		show_line(*(one_piece + line_nb));
		ft_putstr("\n");
		line_nb++;
	}
}

void	show_pieces(char ***pieces)
{
	size_t	piece_nb;

	piece_nb = 0;
	while (*(pieces + piece_nb) != NULL)
	{
		show_one_piece(*(pieces + piece_nb));
		ft_putstr("\n");
		piece_nb++;
	}
}
