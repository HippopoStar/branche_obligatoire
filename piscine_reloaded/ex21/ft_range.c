/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:59:19 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/07 18:38:58 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int			*tab;
	long int	taille;
	long int	i;

	taille = (long int)max - (long int)min;
	if (taille <= 0)
	{
		return (0);
	}
	else
	{
		if (!(tab = (int *)malloc(taille * sizeof(int))))
		{
			return (0);
		}
		i = 0;
		while (i < taille)
		{
			tab[i] = (int)(i + (long int)min);
			i++;
		}
		return (tab);
	}
}
