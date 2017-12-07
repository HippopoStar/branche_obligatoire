
#include "fillit.h"

char	**solve_current(char **grid, size_t v_pos, size_t h_pos, char ***pieces)
{
//	ft_putstr("Appel de \"solve_current\"\n");

	char	**next_grid;
	char	**retour;

	if (*(pieces) == NULL)
	{
		return (grid);
	}
	else if (*(grid + v_pos) == NULL)
	{
		liberate_grid(&grid);
		return (NULL);
	}
	else if (*(*(grid + v_pos) + h_pos) == '\0')
	{
		return (solve_current(grid, v_pos + 1, 0, pieces));
	}
	else
	{
		if (is_available(grid, v_pos, h_pos, *pieces))
		{
			next_grid = copy_grid(grid, current_dim(grid));
			place_one_piece(next_grid, v_pos, h_pos, *pieces);
			return ((retour = solve_current(next_grid, 0, 0, pieces + 1)) != NULL ?
					retour : solve_current(grid, v_pos, h_pos + 1, pieces));
		}
		else
		{
			return (solve_current(grid, v_pos, h_pos + 1, pieces));
		}
	}
}

char	**solve_fillit(char ***pieces, size_t nb_of_pieces)
{
//	ft_putstr("Appel de \"solve_fillit\"\n");

	size_t	dim;
	char	**current_grid;
	char	**definitive_solution;
	char	**retour;

	dim = (nb_of_pieces * 4);
	if (!(definitive_solution = (char **)malloc(sizeof(char *))))
		exit (-1);
	*definitive_solution = NULL;
	current_grid = initialise_grid(dim);
	while ((retour = solve_current(current_grid, 0, 0, pieces)) != NULL)
	{
		liberate_grid(&definitive_solution);
		dim = next_dim(retour);
		definitive_solution = copy_grid(retour, dim);
		liberate_grid(&retour);
		current_grid = initialise_grid(dim - 1);

		show_one_piece(definitive_solution);
		ft_putstr("\n");
	}
	return (definitive_solution);
}
