/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:37:18 by kmjaku            #+#    #+#             */
/*   Updated: 2016/06/03 16:19:54 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c1;

	i = 0;
	str = NULL;
	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == c1)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
