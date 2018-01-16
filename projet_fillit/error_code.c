/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlevaufr <tlevaufr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:12:14 by tlevaufr          #+#    #+#             */
/*   Updated: 2018/01/16 19:14:08 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

void	error_code(char *error_string)
{
	if (error_string != NULL)
	{
		ft_putstr(error_string);
	}
	exit(0);
}
