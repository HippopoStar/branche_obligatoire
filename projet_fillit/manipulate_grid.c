/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:00:04 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/07 15:32:48 by tlevaufr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	next_dim(char **grid)
{
	size_t	dim_v;
	size_t	dim_h;
	size_t	i;
	size_t	j;
	char	c;

	dim_v = 0;
	dim_h = 0;
	i = 0;
	while (*(grid + i) != NULL)
	{
		j = 0;
		while ((c = *(*(grid + i) + j)) != '\0')
		{
			if (c != '.')
			{
				dim_v = (i > dim_v) ? i : dim_v;
				dim_h = (j > dim_h) ? j : dim_h;
			}
			j++;
		}
		i++;
	}
	return ((dim_v > dim_h) ? (dim_v + 1) : (dim_h + 1));
}

char	**initialise_grid(size_t dim)
{
	char	**initial_grid;
	size_t	i;
	size_t	j;

	if (!(initial_grid = (char **)malloc((dim + 1) * sizeof(char *))))
		exit(-1);
	i = 0;
	while (i < dim)
	{
		if (!(*(initial_grid + i) = (char *)malloc((dim + 1) * sizeof(char))))
			exit(-1);
		j = 0;
		while (j < dim)
		{
			*(*(initial_grid + i) + j) = '.';
			j++;
		}
		*(*(initial_grid + i) + dim) = '\0';
		i++;
	}
	*(initial_grid + dim) = NULL;
	return (initial_grid);
}

void	liberate_grid(char ***grid)
{
	size_t	i;

	i = 0;
	while (*((*grid) + i) != NULL)
	{
		free(*((*grid) + i));
		i++;
	}
	free(*grid);
}

char	**copy_grid(char **grid, size_t dim)
{
	char	**grid_copy;
	size_t	i;
	size_t	j;

	if (!(grid_copy = (char **)malloc((dim + 1) * sizeof(char *))))
		exit(-1);
	i = 0;
	while (i < dim)
	{
		if (!(*(grid_copy + i) = (char *)malloc((dim + 1) * sizeof(char))))
			exit(-1);
		j = 0;
		while (j < dim)
		{
			*(*(grid_copy + i) + j) = *(*(grid + i) + j);
			j++;
		}
		*(*(grid_copy + i) + dim) = '\0';
		i++;
	}
	*(grid_copy + dim) = NULL;
	return (grid_copy);
}
