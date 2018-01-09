/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:28:58 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/07 15:26:20 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_line(int fd, char *line, size_t piece_nb)
{
	size_t	column_nb;
	char	c;

	read(fd, line, 4);
	column_nb = 0;
	while (column_nb < 4)
	{
		if (*(line + column_nb) != '.' && *(line + column_nb) != '#')
			error_code("error\n");
		else if (*(line + column_nb) == '#')
			*(line + column_nb) = 'A' + (int)piece_nb;
		column_nb++;
	}
	read(fd, &c, 1);
	if (c != '\n')
		error_code("error\n");
	*(line + 4) = '\0';
}

int		fill_one_piece(int fd, char **one_piece, size_t piece_nb)
{
	size_t	line_nb;
	char	c;

	line_nb = 0;
	while (line_nb < 4)
	{
		if (!(*(one_piece + line_nb) = (char *)malloc((4 + 1) * sizeof(char))))
			exit(-1);
		fill_line(fd, *(one_piece + line_nb), piece_nb);
		line_nb++;
	}
	if ((read(fd, &c, 1)) == 0)
	{
		close(fd);
		return (0);
	}
	else if (c != '\n')
		error_code("error\n");
	*(one_piece + 4) = NULL;
	return (1);
}

void	fill_pieces(int fd, size_t *piece_nb, char ***pieces)
{
	if (*piece_nb == 26)
		error_code("error\n");
	if (!(*(pieces + *piece_nb) = (char **)malloc((4 + 1) * sizeof(char *))))
		exit(-1);
	if (fill_one_piece(fd, *(pieces + *piece_nb), *piece_nb) != 0)
	{
		(*piece_nb)++;
		fill_pieces(fd, piece_nb, pieces);
	}
	else
		*(pieces + ((*piece_nb) + 1)) = NULL;
}

void	fillit(int fd, int colors)
{
	char	**retour;
	char	***pieces;
	size_t	nb_of_pieces;

	nb_of_pieces = 0;
	if (!(pieces = (char ***)malloc((26 + 1) * sizeof(char **))))
		exit(-1);
	fill_pieces(fd, &nb_of_pieces, pieces);
	show_pieces(pieces);
	top_left_corner_pieces(pieces);
	show_pieces(pieces);
	if (!(conform_pieces(pieces)))
		error_code("error\n");
	write(1, "\n", 1);
	epur_pieces(pieces);
	show_pieces(pieces);
	retour = (solve_fillit(pieces, nb_of_pieces));
	colors ? print_grid(retour) : show_one_piece(retour);
	write(1, "\n", 1);
	ft_putstr("Fin de \"fillit\"\n");
}

int		main(int argc, char **argv)
{
	int		fd;
	int		colors;

	if (!(argc == 3 && (colors = colors_or_not(*(argv + 2)))) && argc != 2)
		error_code("\"fillit\" doit prendre un fichier en argument\n");
	else
	{
		if ((fd = open(*(argv + 1), O_RDONLY)) == -1)
			error_code("error\n");
		else
			fillit(fd, colors);
	}
	return (0);
}
