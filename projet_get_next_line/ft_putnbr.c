/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:49:38 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/28 07:56:47 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_putstr(char *str);

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	aux_ft_putnbr(int n)
{
	if (n != 0)
	{
		aux_ft_putnbr(n / 10);
		ft_putchar('0' + (n % 10));
	}
}

void		ft_putnbr(int n)
{
	if (n == 0)
	{
		ft_putchar('0');
	}
	else if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		ft_putchar('-');
		aux_ft_putnbr(-n);
	}
	else
	{
		aux_ft_putnbr(n);
	}
}
