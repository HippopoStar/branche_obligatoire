/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 06:34:10 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 08:17:43 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_putnbr(int nb);
void		ft_putstr(char *str);

//int			get_next_line(const int fd, char **line);
//static int	aux_0_get_next_line(const int fd, char **line);
//static int	aux_1_get_next_line(const int fd, char **line, t_gnl *maillon);
static int	aux_2_get_next_line(const int fd, char **line, t_gnl *maillon);
//static int	aux_3_get_next_line(const int fd, char **line, t_gnl *maillon);

static int	aux_3_get_next_line(const int fd, char **line, t_gnl *maillon)
{
//	ft_putstr("aux_3_get_next_line\n");
//	ft_putnbr((int)(maillon->backspace_place));
//	ft_putstr("\n");
//	ft_putnbr((int)(maillon->bytes_readed));
//	ft_putstr("\n");

	char			*temp;
	size_t			previous_length;
	size_t			to_add;
	size_t			i;

	previous_length = 0;
	while (*((*line) + previous_length) != '\0')
	{
		previous_length++;
	}
	to_add = 0;
	while (*(maillon->BUFFER + maillon->backspace_place + to_add) != '\n'
				&& maillon->backspace_place + to_add < maillon->bytes_readed)
	{
		to_add++;
	}
	if (!(temp = (char *)malloc((previous_length + to_add + 1) * sizeof(char))))
		return (-1);
	i = 0;
	while (i < previous_length)
	{
		*(temp + i) = *((*line) + i);
		i++;
	}
	free (*line);
	i = 0;
	while (i < to_add)
	{
		*(temp + previous_length + i) = *(maillon->BUFFER + maillon->backspace_place);
		i++;
		maillon->backspace_place++;
	}
	*(temp + previous_length + to_add) = '\0';
	*line = temp;
	if (maillon->backspace_place == maillon->bytes_readed)
	{
		return (aux_2_get_next_line(fd, line, maillon));
	}
	else
	{
		maillon->backspace_place++;
		return (1);
	}
}

static int	aux_2_get_next_line(const int fd, char **line, t_gnl *maillon)
{
//	ft_putstr("aux_2_get_next_line\n");

	if (maillon->BUFFER == NULL)
	{
		if (!(maillon->BUFFER = (char *)malloc(BUFF_SIZE * sizeof(char))))
			return (-1);
		maillon->backspace_place = 0;
		maillon->bytes_readed = read(fd, maillon->BUFFER, BUFF_SIZE);
		return (aux_2_get_next_line(fd, line, maillon));
	}
	else if (maillon->bytes_readed == 0)
	{
		return (0);
	}
	else if (maillon->backspace_place == maillon->bytes_readed)
	{
		maillon->bytes_readed = read(fd, maillon->BUFFER, BUFF_SIZE);
		maillon->backspace_place = 0;
		return (aux_2_get_next_line(fd, line, maillon));
	}
	else
	{
		return (aux_3_get_next_line(fd, line, maillon));
	}
}

static int	aux_1_get_next_line(const int fd, char **line, t_gnl *maillon)
{
//	ft_putstr("aux_1_get_next_line\n");

	if (maillon->fd != fd)
	{
		if (maillon->next == NULL)
		{
			if (!(maillon->next = (t_gnl *)malloc(sizeof(t_gnl))))
				return (-1);
			(maillon->next)->fd = fd;
			(maillon->next)->BUFFER = NULL;
		}
		return (aux_1_get_next_line(fd, line, maillon->next));
	}
	else
	{
		return (aux_2_get_next_line(fd, line, maillon));
	}
}

static int	aux_0_get_next_line(const int fd, char **line)
{
//	ft_putstr("aux_0_get_next_line\n");

	static t_gnl	*chaine;

	if (chaine == NULL)
	{
		if (!(chaine = (t_gnl *)malloc(sizeof(t_gnl))))
			return (-1);
		chaine->fd = fd;
		chaine->BUFFER = NULL;
		chaine->next = NULL;
	}
	return (aux_1_get_next_line(fd, line, chaine));
}

int			get_next_line(const int fd, char **line)
{
//	ft_putstr("get_next_line\n");

	if (!((*line) = (char *)malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	return (aux_0_get_next_line(fd, line));
}
