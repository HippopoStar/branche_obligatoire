
#include "fillit.h"

void	epur_one_piece(char **one_piece)
{
	ft_putstr("Debut de \"epur_one_piece\"\n");

	ssize_t	i;
	ssize_t	j;
	int		temoin_v;
	int		temoin_h;

	temoin_v = 0;
	i = 3;
	while (i >= 0)
	{
		temoin_h = 0;
		j = 3;
		while (j >= 0 && temoin_h == 0)
		{
			if (*(*(one_piece + i) + j) == '.')
			{
				*(*(one_piece + i) + j) = '\0';
			}
			else
			{
				temoin_v = 1;
				temoin_h = 1;
			}
			j--;
		}
		if (temoin_v == 0 && temoin_h == 0)
		{
			free(*(one_piece + i));
			*(one_piece + i) = NULL;
		}
		i--;
	}

	ft_putstr("Fin de \"epur_one_piece\"\n");
}

void	epur_pieces(char ***pieces)
{
	ft_putstr("Debut de \"epur_pieces\"\n");

	size_t	i;

	i = 0;
	while (*(pieces + i) != NULL)
	{
		epur_one_piece(*(pieces + i));
		i++;
	}

	ft_putstr("Fin de \"epur_pieces\"\n");
}
