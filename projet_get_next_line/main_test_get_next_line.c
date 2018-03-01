/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 07:12:57 by lcabanes          #+#    #+#             */
/*   Updated: 2018/01/16 16:49:29 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		*fd;
	int		retour;
	char	*line;
	size_t	i;
	size_t	j;
	int		temoin;

	if (argc < 3)
	{
		ft_putstr("Le premier argument doit etre '0' ou '1'\
				(respectivement pour lire les fichiers a la suite les uns des autres, \
				 et pour lire alternativement une ligne de chaque fichier)\n");
		return (0);
	}
	if (!(fd = (int *)malloc((argc - 2) * sizeof(int))))
		return (0);
	i = 0;
	while (i < (size_t)(argc - 2))
	{
		*(fd + i) = open(*((argv + 2) + i), O_RDONLY);
		i++;
	}
	if (*(*(argv + 1) + 0) == '0')
	{
		i = 0;
		while (i < (size_t)(argc - 2))
		{
			while (get_next_line(*(fd + i), &line))
			{
				ft_putstr(line);
				write(1, "\n", 1);
			}
			i++;
		}
	}
	else if (*(*(argv + 1) + 0) == '1')
	{
		i = 0;
		temoin = 1;
		while (temoin != 0)
		{
			j = 0;
			temoin = 0;
			while (j < (size_t)(argc - 2))
			{
				if ((retour = get_next_line(*(fd + (i % (argc - 2))), &line)) != 0)
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
	}
	return (0);
}
