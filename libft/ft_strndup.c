/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:49:51 by kmjaku            #+#    #+#             */
/*   Updated: 2016/11/23 02:06:20 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(char *src, int len)
{
	char	*dest;
	char	*ptr;

	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	while (src[len] && len--)
		dest[len] = src[len];
	ptr = ft_strdup(dest);
	free(dest);
	dest = ptr;
	return (dest);
}
