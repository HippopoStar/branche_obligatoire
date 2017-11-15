/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcabanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:15:23 by lcabanes          #+#    #+#             */
/*   Updated: 2017/11/10 17:21:02 by lcabanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*mapi;

	length = ft_strlen(s);
	if (!(mapi = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < length)
	{
		*(mapi + i) = f((unsigned int)i, *(s + i));
		i++;
	}
	*(mapi + length) = '\0';
	return (mapi);
}
