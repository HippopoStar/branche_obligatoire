# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 22:48:14 by lcabanes          #+#    #+#              #
#    Updated: 2017/12/14 15:08:21 by Theo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./

NAME = fillit

SRCS = main_fillit.c\
	   top_left.c\
	   conform_pieces.c\
	   epur.c\
	   place_one_piece.c\
	   solve_fillit.c\
	   aux_solve_fillit.c\
	   manipulate_grid.c\
	   show_pieces.c\
	   color.c\
	   ft_putstr.c\
	   error_code.c

OBJS = main_fillit.o\
	   top_left.o\
	   conform_pieces.o\
	   epur.o\
	   place_one_piece.o\
	   solve_fillit.o\
	   aux_solve_fillit.o\
	   manipulate_grid.o\
	   show_pieces.o\
	   color.o\
	   ft_putstr.o\
	   error_code.o

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
