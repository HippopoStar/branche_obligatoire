/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 06:34:10 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/17 20:03:44 by lcabanes         ###   ########.fr       */
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

	char			*tmp;
	ssize_t			previous_length;
	ssize_t			to_add;
	ssize_t			i;
	int				retour;

	previous_length = 0;
	while (*((*line) + previous_length) != '\0')
	{
		previous_length++;
	}
	to_add = 0;
	while (*(maillon->buff + maillon->bs_p + to_add) != '\n'
				&& maillon->bs_p + to_add < maillon->r_v)
	{
		to_add++;
	}
	if (!(tmp = (char *)malloc((previous_length + to_add + 1) * sizeof(char))))
		return (-1);
	i = 0;
	while (i < previous_length)
	{
		*(tmp + i) = *((*line) + i);
		i++;
	}
	free (*line);
	i = 0;
	while (i < to_add)
	{
		*(tmp + previous_length + i) = *(maillon->buff + maillon->bs_p);
		i++;
		maillon->bs_p++;
	}
	*(tmp + previous_length + to_add) = '\0';
	*line = tmp;
	if (maillon->bs_p == maillon->r_v)
	{
		return ((retour = aux_2_get_next_line(fd, line, maillon)) == 0 ? 1 : retour);
	}
	else
	{
		maillon->bs_p++;
		return (1);
	}
}

static int	aux_2_get_next_line(const int fd, char **line, t_gnl *maillon)
{
//	ft_putstr("aux_2_get_next_line\n");

	if (maillon->r_v == 0)
	{
//		*(maillon->BUFFER + 0) = '\0';
		return (0);
	}
	else if (maillon->bs_p == maillon->r_v)
	{
		if ((maillon->r_v = read(fd, maillon->buff, BUFF_SIZE)) == -1)
			return (-1);
		maillon->bs_p = 0;
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
			(maillon->next)->bs_p = 0;
			if (((maillon->next)->r_v = read(fd, (maillon->next)->buff, BUFF_SIZE)) == -1)
			{
				free(maillon->next);
				maillon->next = NULL;
				return (-1);
			}
			(maillon->next)->next = NULL;
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
		chaine->bs_p = 0;
		if ((chaine->r_v = read(fd, chaine->buff, BUFF_SIZE)) == -1)
		{
			free(chaine);
			chaine = NULL;
			return (-1);
		}
		chaine->next = NULL;
	}
	return (aux_1_get_next_line(fd, line, chaine));
}

int			get_next_line(const int fd, char **line)
{
//	ft_putstr("get_next_line\n");

	int		retour;

	if (line == NULL)
	{
		return (-1);
	}
	if (!((*line) = (char *)malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if ((retour = aux_0_get_next_line(fd, line)) == -1 || retour == 0)
	{
		free(*line);
		*line = NULL;
	}
	return (retour);
}
