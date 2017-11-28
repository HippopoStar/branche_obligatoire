/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 07:12:57 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 21:41:06 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	size_t	length;

	length = ft_strlen(str);
	write(1, str, length);
}

int		main(int argc, char **argv)
{
	int		*fd;
	int		retour;
	char	*line;
	size_t	i;
	size_t	j;
	int		temoin;

	if (argc < 2)
	{
		ft_putstr("NOPE\n");
		return (0);
	}
	if (!(fd = (int *)malloc((argc - 1) * sizeof(int))))
		return (0);
	i = 0;
	while (i < (size_t)(argc - 1))
	{
		*(fd + i) = open(*((argv + 1) + i), O_RDONLY);
		i++;
	}
	i = 0;
	temoin = 1;
	while (temoin != 0)
	{
		j = 0;
		temoin = 0;
		while (j < (size_t)(argc - 1))
		{
			if ((retour = get_next_line(*(fd + (i % (argc - 1))), &line)) != 0)
			{
				temoin = 1;
			}
			if (retour == -1)
			{
				ft_putstr("Une erreur est survenue\n");
				return (0);
			}
			ft_putstr(line);
			if (retour != 0)
			{
				ft_putstr("\n");
			}
			j++;
			i++;
		}
	}
	return (0);
}
