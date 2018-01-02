/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:59:46 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/02 14:59:59 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		colors_or_not(char *argv_2)
{
	char	*colors_instruction;
	size_t	i;

	if (!(colors_instruction = (char *)malloc(10 * sizeof(char))))
		exit(-1);
	*(colors_instruction + 0) = 'C';
	*(colors_instruction + 1) = 'O';
	*(colors_instruction + 2) = 'L';
	*(colors_instruction + 3) = 'O';
	*(colors_instruction + 4) = 'R';
	*(colors_instruction + 5) = 'S';
	*(colors_instruction + 6) = '=';
	*(colors_instruction + 7) = 'O';
	*(colors_instruction + 8) = 'N';
	*(colors_instruction + 9) = '\0';
	i = 0;
	while (i < 10)
	{
		if (*(colors_instruction + i) != *(argv_2 + i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*initialise_color(void)
{
	char	*color;

	if (!(color = (char *)malloc(6 * sizeof(char))))
		exit(-1);
	*(color + 0) = '\033';
	*(color + 1) = '[';
	*(color + 2) = '0';
	*(color + 3) = '0';
	*(color + 4) = 'm';
	*(color + 5) = '\0';
	return (color);
}

void	write_color(char c, char *color)
{
	if (c == '.')
	{
		write(1, &c, 1);
	}
	else
	{
		*(color + 3) = '1';
		write(1, color, 6);
		*(color + 2) = '3';
		*(color + 3) = '1' + ((c - 'A') % 6);
		write(1, color, 6);
		write(1, &c, 1);
		*(color + 2) = '0';
		*(color + 3) = '0';
		write(1, color, 6);
	}
}

void	print_grid(char **grid)
{
	size_t	i;
	size_t	j;
	char	*color;
	char	c;

	color = initialise_color();
	i = 0;
	while (*(grid + i) != NULL)
	{
		j = 0;
		while ((c = *(*(grid + i) + j)) != '\0')
		{
			write_color(c, color);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
