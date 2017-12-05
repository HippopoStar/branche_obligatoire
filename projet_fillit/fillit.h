/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:30:07 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/27 23:55:32 by lcabanes         ###   ########.fr       */
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

void	show_pieces(char ***pieces);
void	show_one_piece(char **one_piece);
void	show_line(char *line);

void	epur_pieces(char ***pieces);
void	epur_one_piece(char **one_piece);

void	top_left_corner_pieces(char ***pieces);
void	top_left_corner_one_piece(char **one_piece);
void	decal(char **one_piece, size_t top, size_t left);

void	fillit(int fd);
void	fill_pieces(int fd, size_t *piece_nb, char ***pieces);
int		fill_one_piece(int fd, char **one_piece, size_t piece_nb);
void	fill_line(int fd, char *line, size_t piece_nb);

#endif
