/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:50:49 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/15 20:25:05 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;
	unsigned char	*temp;

	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	if (!(temp = (unsigned char *)malloc((len + 1) * sizeof(unsigned char))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(temp + i) = *(cast_src + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		*(cast_dst + i) = *(temp + i);
		i++;
	}
	free(temp);
	return (dst);
}
