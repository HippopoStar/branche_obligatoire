
#include "fillit.h"

/*
** max_dim = 4 * (racine_carree de nb_of_pieces)
** max_dim = 4 * (racine carree de (nb_of_characters / 4))
** max_dim = 4 * ((racine_carree de nb_of_caracters) / 2)
** max_dim = 2 * (racine_carree de nb_of_characters)
** max_dim = 2 * min_dim
*/

size_t	calculate_min_dim(size_t nb_of_pieces)
{
	size_t	i;
	size_t	i_square;
	size_t	nb_of_characters;

	nb_of_characters = 4 * (nb_of_pieces + 1);
	i = 0;
	while ((i_square = i * i) < nb_of_characters)
	{
		i++;
	}
	return ((i_square == nb_of_characters) ? i : (i + 1));
}

char	**solve_current(char **grid, size_t v_pos, size_t h_pos, char ***pieces)
{
//	ft_putstr("Appel de \"solve_current\"\n");

	char	**retour;

	if (*(pieces) == NULL)
	{
		show_one_piece(grid);
		write(1, "\n", 1);
		ft_putstr("YEAH ! =D\n\n");
		return (grid);
	}
	else if (*(grid + v_pos) == NULL)
	{
		ft_putstr("NOPE =|\n\n");
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
			if ((retour = aux0_solve_current(grid, v_pos, h_pos, pieces)) != NULL)
			{
				return (retour);
			}
			return (aux1_solve_current(grid, v_pos, h_pos, pieces));
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
	size_t	min_dim;
	char	**current_grid;
	char	**definitive_solution;
	char	**retour;

	min_dim = calculate_min_dim(nb_of_pieces);
	dim = min_dim * 2;
	if (!(definitive_solution = (char **)malloc(sizeof(char *))))
		exit (-1);
	*definitive_solution = NULL;
	current_grid = initialise_grid(dim);

	show_one_piece(current_grid);
	write(1, "\n", 1);

	while (dim > min_dim && (retour = solve_current(current_grid, 0, 0, pieces)) != NULL)
	{
		liberate_grid(&definitive_solution);
		dim = next_dim(retour);
		definitive_solution = copy_grid(retour, dim);
		liberate_grid(&retour);
		current_grid = initialise_grid(dim - 1);

		show_one_piece(definitive_solution);
		write(1, "\n", 1);

		show_one_piece(current_grid);
		write(1, "\n", 1);

	}
	return (definitive_solution);
}
