
#include "fillit.h"

int	is_available(char **grid, size_t v_pos, size_t h_pos, char **one_piece)
{
	size_t	i;
	size_t	j;
	char	c_grid;
	char	c_one_piece;

	i = 0;
	while (*(one_piece + i) != NULL)
	{
		if (*(grid + (v_pos + i)) == NULL)
		{
			return (0);
		}
		j = 0;
		while ((c_one_piece = *(*(one_piece + i) + j)) != '\0')
		{
			if ((c_grid = *(*(grid + (v_pos + i)) + (h_pos + j))) == '\0')
			{
				return (0);
			}
			if (c_one_piece != '.' && c_grid != '.')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	place_one_piece(char **grid, size_t v_pos, size_t h_pos, char **one_piece)
{
	size_t	i;
	size_t	j;
	char	c;

	i = 0;
	while (*(one_piece + i) != NULL)
	{
		j = 0;
		while ((c = *(*(one_piece + i) + j)) != '\0')
		{
			if (c != '.')
			{
				*(*(grid + (v_pos + i)) + (h_pos + j)) = c;
			}
			j++;
		}
		i++;
	}
}
