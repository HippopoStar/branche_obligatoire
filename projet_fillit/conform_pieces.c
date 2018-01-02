/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conform_pieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:47:45 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/02 16:46:28 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		match_that_piece(int fd, char **one_piece, char *read_buf)
{
	int		total_read;
	char	c;
	int		i;
	int		j;

	total_read = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (read(fd, &c, 1) != 1)
				return (0);
			total_read++;
			if (c == '.' && c != *(*(one_piece + i) + j))
			{
				if (read(fd, read_buf, (20 - total_read)) != (20 - total_read))
					return (0);
				return (0);
			}
		}
		if (read(fd, read_buf, 1) != 1)
			return (0);
		total_read++;
	}
	return (1);
}

int		match_a_piece(int fd, char **one_piece, int read_value, char *read_buf)
{
	if (read_value != 1)
	{
		close(fd);
		return (0);
	}
	else if (match_that_piece(fd, one_piece, read_buf))
	{
		close(fd);
		return (1);
	}
	else
	{
		read_value = read(fd, read_buf, 1);
		return (match_a_piece(fd, one_piece, read_value, read_buf));
	}
}

int		conform_one_piece(char **one_piece, char *read_buf)
{
	int		fd;

	if ((fd = open("[PROTECT]conform_forms", O_RDONLY)) == -1)
		return (0);
	return (match_a_piece(fd, one_piece, 1, read_buf));
}

int		conform_piece_i(char ***piece_i, char *read_buf)
{
	if (*piece_i == NULL)
	{
		free(read_buf);
		return (1);
	}
	else
	{
		return (conform_one_piece(*piece_i, read_buf) &&\
				conform_piece_i((piece_i + 1), read_buf));
	}
}

int		conform_pieces(char ***pieces)
{
	char	*read_buf;

	if (!(read_buf = (char *)malloc((20 + 1) * sizeof(char))))
		return (0);
	*(read_buf + 20) = '\0';
	return (conform_piece_i((pieces + 0), read_buf));
}
