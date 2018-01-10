/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 15:41:59 by kmjaku            #+#    #+#             */
/*   Updated: 2016/08/28 19:06:54 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len;
	char		*dest;

	dest = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		dest = (char*)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			i = 0;
			while (*s1)
				dest[i++] = *s1++;
			while (*s2)
				dest[i++] = *s2++;
			dest[i] = '\0';
		}
	}
	else if (s1)
		dest = ft_strdup(s1);
	else if (s2)
		dest = ft_strdup(s1);
	return (dest);
}
