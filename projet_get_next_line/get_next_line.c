/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 06:34:10 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/17 22:04:12 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*creer_maillon(const int fd)
{
	t_gnl			*maillon;

	if (!(maillon = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	maillon->fd = fd;
	maillon->bs_p = 0;
	if ((maillon->r_v = read(fd, maillon->buff, BUFF_SIZE)) == -1)
	{
		free(maillon);
		return (NULL);
	}
	maillon->next = NULL;
	return (maillon);
}

int				aux_3_gnl(const int fd, char **line, t_gnl *mai, ssize_t tab[2])
{
	char			*tmp;
	ssize_t			i;
	int				retour;

	while (*((*line) + tab[0]) != '\0')
		tab[0]++;
	while (*(mai->buff + mai->bs_p + tab[1]) != '\n'
				&& mai->bs_p + tab[1] < mai->r_v)
		tab[1]++;
	if (!(tmp = (char *)malloc((tab[0] + tab[1] + 1) * sizeof(char))))
		return (-1);
	i = -1;
	while (++i < tab[0])
		*(tmp + i) = *((*line) + i);
	free(*line);
	i = -1;
	while (++i < tab[1] && ++(mai->bs_p))
		*(tmp + tab[0] + i) = *(mai->buff + mai->bs_p - 1);
	*(tmp + tab[0] + tab[1]) = '\0';
	*line = tmp;
	if (mai->bs_p == mai->r_v)
		return ((retour = aux_2_gnl(fd, line, mai)) == 0 ? 1 : retour);
	mai->bs_p++;
	return (1);
}

int				aux_2_gnl(const int fd, char **line, t_gnl *maillon)
{
	ssize_t			p_l__t_a[2];

	if (maillon->r_v == 0)
	{
		return (0);
	}
	else if (maillon->bs_p == maillon->r_v)
	{
		if ((maillon->r_v = read(fd, maillon->buff, BUFF_SIZE)) == -1)
			return (-1);
		maillon->bs_p = 0;
		return (aux_2_gnl(fd, line, maillon));
	}
	else
	{
		p_l__t_a[0] = 0;
		p_l__t_a[1] = 0;
		return (aux_3_gnl(fd, line, maillon, p_l__t_a));
	}
}

int				aux_1_gnl(const int fd, char **line, t_gnl *maillon)
{
	if (maillon->fd != fd)
	{
		if (maillon->next == NULL)
		{
			if (!(maillon->next = creer_maillon(fd)))
				return (-1);
		}
		return (aux_1_gnl(fd, line, maillon->next));
	}
	else
	{
		return (aux_2_gnl(fd, line, maillon));
	}
}

int				get_next_line(const int fd, char **line)
{
	int				retour;
	static t_gnl	*chaine;

	if (line == NULL)
	{
		return (-1);
	}
	if (!((*line) = (char *)malloc(sizeof(char))))
		return (-1);
	**line = '\0';
	if (chaine == NULL)
	{
		if (!(chaine = creer_maillon(fd)))
		{
			free(*line);
			*line = NULL;
			return (-1);
		}
	}
	if ((retour = aux_1_gnl(fd, line, chaine)) == -1 || retour == 0)
	{
		free(*line);
		*line = NULL;
	}
	return (retour);
}
