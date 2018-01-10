/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:38:23 by kmjaku            #+#    #+#             */
/*   Updated: 2016/05/30 14:43:26 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	str = NULL;
	if (s && f)
	{
		str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str)
		{
			i = 0;
			while (s[i])
			{
				str[i] = f(s[i]);
				i++;
			}
			str[i] = '\0';
		}
	}
	return (str);
}
