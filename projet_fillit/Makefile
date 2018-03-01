# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 22:48:14 by lcabanes          #+#    #+#              #
#    Updated: 2018/02/28 14:41:21 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./fillit_files/ -I./libft/

NAME = fillit

SRCS = ./fillit_files/main_fillit.c\
	   ./fillit_files/top_left.c\
	   ./fillit_files/tetriminos.c\
	   ./fillit_files/epur.c\
	   ./fillit_files/place_one_piece.c\
	   ./fillit_files/solve_fillit.c\
	   ./fillit_files/aux_solve_fillit.c\
	   ./fillit_files/manipulate_grid.c\
	   ./fillit_files/show_pieces.c\
	   ./fillit_files/color.c\
	   ./fillit_files/ft_error_code.c

OBJS = main_fillit.o\
	   top_left.o\
	   tetriminos.o\
	   epur.o\
	   place_one_piece.o\
	   solve_fillit.o\
	   aux_solve_fillit.o\
	   manipulate_grid.o\
	   show_pieces.o\
	   color.o\
	   ft_error_code.o

all: $(NAME)

$(NAME):
	@make -C ./libft/ all
	gcc -c $(CFLAGS) $(SRCS)
	gcc -o $(NAME) $(CFLAGS) -L./libft/ $(OBJS) -lft

clean:
	@make -C ./libft/ clean
	rm -f $(OBJS)

fclean: clean
	@make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY	:				all clean fclean re
