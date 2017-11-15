/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:41:10 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/15 18:49:11 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	byte;
	unsigned char	*cast_dst;
	unsigned char	*cast_src;

	byte = (unsigned char)c;
	cast_dst = (unsigned char *)dst;
	cast_src = (unsigned char *)src;
	i = 0;
	while (i < n && *(cast_src + i) != byte)
	{
		*(cast_dst + i) = *(cast_src + i);
		i++;
	}
	if (i < n)
	{
		return ((dst + i));
	}
	else
	{
		return (NULL);
	}
}
