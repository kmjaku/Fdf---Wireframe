/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:01:41 by kmjaku            #+#    #+#             */
/*   Updated: 2016/06/03 18:42:38 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	int		i;
	int		k;
	int		s;

	if (!*little)
		return (char *)(big);
	i = 0;
	while (big[i] && len > 0)
	{
		if (len < ft_strlen(little))
			return (NULL);
		k = 0;
		s = i;
		while (big[s] == little[k] && little[k] && big[s])
		{
			k++;
			s++;
		}
		if (little[k] == '\0')
			return ((char *)big + i);
		len--;
		i++;
	}
	return (NULL);
}
