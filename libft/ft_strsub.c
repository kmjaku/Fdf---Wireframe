/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:17:01 by kmjaku            #+#    #+#             */
/*   Updated: 2016/09/02 15:23:21 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	dest = ft_memalloc(1);
	if (s && len > 0)
	{
		dest = (char*)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			i = 0;
			while (len--)
				dest[i++] = s[start++];
			dest[i] = '\0';
		}
	}
	return (dest);
}
