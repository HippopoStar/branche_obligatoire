/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:30:07 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/31 15:30:26 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
void	ft_putstr(char *str);

void	print_grid(char **grid);
void	write_color(char c, char *color);
char	*initialise_color(void);
int		colors_or_not(char *argv_2);

void	show_pieces(char ***pieces);
void	show_one_piece(char **one_piece);
void	show_line(char *line);

char	**copy_grid(char **grid, size_t dim);
void	liberate_grid(char ***grid);
char	**initialise_grid(size_t dim);
size_t	next_dim(char **grid);

char	**aux0_solve_current(char **grid, size_t v_pos, size_t h_pos,\
							char ***pieces);
char	**aux1_solve_current(char **grid, size_t v_pos, size_t h_pos,\
							char ***pieces);

char	**solve_fillit(char ***pieces, size_t nb_of_pieces);
char	**solve_current(char **grid, size_t v_pos, size_t h_pos,\
						char ***pieces);
size_t	calculate_max_dim(size_t nb_of_pieces);
size_t	calculate_min_dim(size_t nb_of_pieces);

void	place_one_piece(char **grid, size_t v_pos, size_t h_pos,\
						char **one_piece);
int		is_available(char **grid, size_t v_pos, size_t h_pos,\
					char **one_piece);
void	unplace_one_piece(char **grid, size_t v_pos, size_t h_pos,\
						char **one_piece);

void	epur_pieces(char ***pieces);
void	epur_one_piece(char **one_piece);

int		conform_pieces(char ***pieces);
int		conform_piece_i(char ***piece_i, char *read_buf);
int		conform_one_piece(char **one_piece, char *read_buf);
int		match_a_piece(int fd, char **one_piece, int read_value, char *read_buf);
int		match_that_piece(int fd, char **one_piece, char *read_buf, int total_r);

int		tetriminos(char ***pieces);
int		tetrimino(char **one_piece);

void	top_left_corner_pieces(char ***pieces);
void	top_left_corner_one_piece(char **one_piece);
void	decal(char **one_piece, size_t top, size_t left);

void	fillit(int fd, int colors);
void	fill_pieces(int fd, size_t *piece_nb, char ***pieces);
int		fill_one_piece(int fd, char **one_piece, size_t piece_nb);
void	fill_line(int fd, char *line, size_t piece_nb);

void	error_code(char *error_string);

#endif
