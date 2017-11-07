/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex13.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:44:18 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 14:47:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_recursive_factorial(int nb);

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%i", ft_recursive_factorial(atoi(*(argv + 1))));
	return (0);
}
