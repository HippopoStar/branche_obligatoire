/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 07:12:57 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 08:18:43 by lcabanes         ###   ########.fr       */
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
	int		fd;
	int		retour;
	char	*line;

	if (argc != 2)
	{
		ft_putstr("NOPE\n");
		return (0);
	}
	fd = open(*(argv + 1), O_RDONLY);
	while ((retour = get_next_line(fd, &line)) != 0)
	{
		if (retour == -1)
		{
			ft_putstr("Une erreur est survenue\n");
			return (0);
		}
		ft_putstr(line);
		ft_putstr("\n");
	}
	return (0);
}
