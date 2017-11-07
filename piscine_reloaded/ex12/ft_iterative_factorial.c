/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:21:06 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 14:30:12 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		a;
	int		i;

	a = 1;
	i = 1;
	if ((nb < 0) || (nb > 12))
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		while (i <= nb)
		{
			a = a * i;
			i++;
		}
		return (a);
	}
}
