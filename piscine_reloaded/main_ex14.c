/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex14.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:54:49 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 14:58:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_sqrt(int nb);

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%i", ft_sqrt(atoi(*(argv + 1))));
	return (0);
}
