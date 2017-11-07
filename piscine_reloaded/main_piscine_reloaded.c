/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_piscine_reloaded.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:51:59 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 14:09:30 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);
void	ft_print_numbers(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	(void)argc;
	if (*(*(argv + 1) + 0) == '6')
	{
		ft_print_alphabet();
	}
	else if (*(*(argv + 1) + 0) == '7')
	{
		ft_print_numbers();
	}
	return (0);
}
