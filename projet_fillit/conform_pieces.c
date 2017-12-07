
#include "fillit.h"

int		match_that_piece(int fd, char **one_piece, char *read_buf)
{
	ft_putstr("Appel de \"match_that_piece\"\n");

	int		total_readed;
	char	c;
	size_t	i;
	size_t	j;

	total_readed = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (read(fd, &c, 1) != 1)
				return (0); //a developper
			total_readed++;
			if (c == '.' && c != *(*(one_piece + i) + j))
			{
				if (read(fd, read_buf, (20 - total_readed)) != (20 - total_readed))
					return (0); //a developper
				return (0);
			}
			j++;
		}
		if (read(fd, read_buf, 1) != 1)
			return (0); //a developper
		total_readed++;
		i++;
	}

	ft_putstr("MATCH !\n");

	return (1);
}

int		match_a_piece(int fd, char **one_piece, int read_value, char *read_buf)
{
	ft_putstr("Appel de \"match_a_piece\"\n");

	if (read_value != 1)
	{
		close(fd);
		return (0); //a developper
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
	ft_putstr("Appel de \"conform_one_piece\"\n");

	int		fd;

	if ((fd = open("[PROTECT]conform_forms", O_RDONLY)) == -1)
		return (0); //a developper
	return (match_a_piece(fd, one_piece, 1, read_buf));
}

int		conform_piece_i(char ***piece_i, char *read_buf)
{
	ft_putstr("Appel de \"conform_piece_i\"\n");

	if (*piece_i == NULL)
	{
		free(read_buf);
		return (1);
	}
	else
	{
		return (conform_one_piece(*piece_i, read_buf) && conform_piece_i((piece_i + 1), read_buf));
	}
}

int		conform_pieces(char ***pieces)
{
	char	*read_buf;

	if (!(read_buf = (char *)malloc((20 + 1) * sizeof(char))))
		return (0); //a developper
	*(read_buf + 20) = '\0';
	return (conform_piece_i((pieces + 0), read_buf));
}
