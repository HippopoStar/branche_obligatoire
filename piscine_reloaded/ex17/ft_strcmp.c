/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:10:01 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/06 15:13:51 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
