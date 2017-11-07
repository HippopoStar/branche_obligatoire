/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:35:23 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/07 18:21:53 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (*(str + i) != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		length;
	char	*dest;

	length = ft_strlen(src);
	if (!(dest = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i <= length)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	return (dest);
}
