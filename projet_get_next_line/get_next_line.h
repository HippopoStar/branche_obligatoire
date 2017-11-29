/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 06:30:14 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/29 06:08:15 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 24

typedef struct		s_gnl
{
	int				fd;
	char			*BUFFER;
	ssize_t			backspace_place;
	ssize_t			bytes_readed;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
//static int			aux_0_get_next_line(const int fd, char **line);
//static int			aux_1_get_next_line(const int fd, char **line, t_gnl *maillon);
//static int			aux_2_get_next_line(const int fd, char **line, t_gnl *maillon);
//static int			aux_3_get_next_line(const int fd, char **line, t_gnl *maillon);

#endif
