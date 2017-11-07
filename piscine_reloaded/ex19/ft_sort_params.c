/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:36:33 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 16:34:09 by lcabanes         ###   ########.fr       */
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

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	ft_str_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_print_params(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(*(argv + i));
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		temoin;

	temoin = 1;
	if (argc > 1)
	{
		while (temoin == 1)
		{
			temoin = 0;
			i = 1;
			while (i < argc - 1)
			{
				if (ft_strcmp(*(argv + i), *(argv + i + 1)) > 0)
				{
					ft_str_swap((argv + i), (argv + i + 1));
					temoin = 1;
				}
				i++;
			}
		}
	}
	ft_print_params(argc, argv);
	return (0);
}
