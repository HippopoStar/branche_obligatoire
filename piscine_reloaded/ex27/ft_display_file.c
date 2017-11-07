/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:00:11 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/07 19:06:30 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_display_files(char *file_name)
{
	int		file_descriptor;
	char	current_letter;

	if ((file_descriptor = open(file_name, O_RDONLY)) == -1)
	{
		return (1);
	}
	else
	{
		while (read(file_descriptor, &current_letter, 1))
		{
			write(1, &current_letter, 1);
		}
	}
	close(file_descriptor);
	return (0);
}

void	show_error(int error_code)
{
	if (error_code == 0)
	{
		write(2, "File name missing.\n", 19);
	}
	else if (error_code == 1)
	{
		write(2, "Too many arguments.\n", 20);
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	{
		show_error(0);
	}
	else if (argc > 2)
	{
		show_error(1);
	}
	else
	{
		if (ft_display_files(*(argv + 1)) != 0)
		{
			show_error(2);
		}
	}
	return (0);
}
