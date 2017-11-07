/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:24:04 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 15:33:03 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
	{
		return (0);
	}
	else
	{
		while (i < argc)
		{
			ft_putstr(*(argv + i));
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
