
#include "fillit.h"

char	**aux0_solve_current(char **grid, size_t v_pos, size_t h_pos, char ***pieces)
{
//	ft_putstr("Debut de \"aux0_solve_current\"\n");
//	show_one_piece(grid);
//	write(1, "\n", 1);
	place_one_piece(grid, v_pos, h_pos, *pieces);
//	show_one_piece(grid);
//	write(1, "\n", 1);
	return (solve_current(grid, 0, 0, pieces + 1));
}

char	**aux1_solve_current(char **grid, size_t v_pos, size_t h_pos, char ***pieces)
{
//	ft_putstr("Debut de \"aux1_solve_current\"\n");
//	show_one_piece(grid);
//	write(1, "\n", 1);
	unplace_one_piece(grid, v_pos, h_pos, *pieces);
//	show_one_piece(grid);
//	write(1, "\n", 1);
	return (solve_current(grid, v_pos, h_pos + 1, pieces));
}
