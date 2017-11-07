/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ex17.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:14:14 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 15:23:01 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);

int		main(int argc, char **argv)
{
	if (argc < 3)
	{
		return (0);
	}
	printf("%i", ft_strcmp(*(argv + 1), *(argv + 2)));
	return (0);
}
