# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 19:50:49 by lcabanes          #+#    #+#              #
#    Updated: 2018/02/28 18:28:58 by lcabanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	+=		-Wall -Wextra -Werror
CFLAGS	+=		-I./ -I./libft/includes/

NAME = test_get_next_line.exe

SRCS = main_test_get_next_line.c\
		get_next_line.c

OBJS = main_test_get_next_line.o\
		get_next_line.o

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
