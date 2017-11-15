/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:59:04 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/09 13:00:29 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_of_digit(int n)
{
	size_t	compteur;

	compteur = 0;
	if (n < 0)
	{
		compteur++;
		n = -n;
	}
	while (n > 0)
	{
		compteur++;
		n = n / 10;
	}
	return (compteur);
}

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	length;
	char	*chaine;

	length = nbr_of_digit(n);
	if (!(chaine = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	if (n == 0)
	{
		*(chaine + 0) = '0';
	}
	else if (n < 0)
	{
		*(chaine + 0) = '-';
		n = -n;
	}
	*(chaine + length) = '\0';
	i = 1;
	while (n > 0)
	{
		*(chaine + length - i) = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (chaine);
}
