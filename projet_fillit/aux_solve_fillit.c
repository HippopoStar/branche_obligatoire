
#include "fillit.h"

char	**aux0_solve_current(char **grid, size_t v_pos, size_t h_pos, char ***pieces)
{
//	ft_putstr("Appel de \"aux0_solve_current\"\n");
	place_one_piece(grid, v_pos, h_pos, *pieces);
//	show_one_piece(grid);
//	write(1, "\n", 1);
	return (solve_current(grid, 0, 0, pieces + 1));
}

char	**aux1_solve_current(char **grid, size_t v_pos, size_t h_pos, char ***pieces)
{
//	ft_putstr("Appel de \"aux1_solve_current\"\n");
	unplace_one_piece(grid, v_pos, h_pos, *pieces);
//	show_one_piece(grid);
//	write(1, "\n", 1);
	return (solve_current(grid, v_pos, h_pos + 1, pieces));
}
