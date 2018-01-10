/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:45:13 by kmjaku            #+#    #+#             */
/*   Updated: 2016/07/05 14:24:37 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	ft_strcpy(new, s);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, new[i]);
		i++;
	}
	return (new);
}
