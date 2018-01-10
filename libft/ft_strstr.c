/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:38:10 by kmjaku            #+#    #+#             */
/*   Updated: 2016/06/03 18:38:42 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *big, char *little)
{
	size_t		size;

	if (*little == '\0')
		return ((char *)big);
	size = ft_strlen(little);
	while (*big)
	{
		if (ft_strncmp(big, little, size) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
