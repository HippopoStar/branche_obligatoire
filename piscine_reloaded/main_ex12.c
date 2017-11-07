/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:31:05 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 14:36:24 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_iterative_factorial(int nb);

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%i", ft_iterative_factorial(atoi(*(argv + 1))));
	return (0);
}
