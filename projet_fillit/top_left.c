
#include "fillit.h"

void	decal(char **one_piece, size_t top, size_t left)
{
//	ft_putstr("Debut de \"decal\"\n");

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
//	ft_putstr("Fin de \"decal\"\n");
}

void	top_left_corner_one_piece(char **one_piece)
{
//	ft_putstr("Debut de \"top_left_corner_one_piece\"\n");

	size_t	i;
	size_t	j;
	size_t	top;
	size_t	left;

	top = 4;
	left = 4;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ('A' <= *(*(one_piece + i) + j) && *(*(one_piece + i) + j) <= 'Z')
			{
				if (i < top)
					top = i;
				if (j < left)
					left = j;
			}
			j++;
		}
		i++;
	}
	if (top || left)
	{
		decal(one_piece, top, left);
	}

//	ft_putstr("Fin de \"top_left_corner_one_piece\"\n");
}

void	top_left_corner_pieces(char ***pieces)
{
	ft_putstr("Debut de \"top_left_corner_pieces\"\n");

	size_t	i;

	i = 0;
	while (*(pieces + i) != NULL)
	{
		top_left_corner_one_piece(*(pieces + i));
		i++;
	}

	ft_putstr("Fin de \"top_left_corner_pieces\"\n");
}
