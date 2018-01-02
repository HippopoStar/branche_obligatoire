/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_solve_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:10:15 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/02 14:11:51 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**aux0_solve_current(char **grid, size_t v_pos, size_t h_pos,\
		char ***pieces)
{
	place_one_piece(grid, v_pos, h_pos, *pieces);
	return (solve_current(grid, 0, 0, pieces + 1));
}

char	**aux1_solve_current(char **grid, size_t v_pos, size_t h_pos,\
		char ***pieces)
{
	unplace_one_piece(grid, v_pos, h_pos, *pieces);
	return (solve_current(grid, v_pos, h_pos + 1, pieces));
}
