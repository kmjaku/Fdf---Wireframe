/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:15:51 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/23 00:00:09 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = NULL;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		i = 0;
		while (i <= size)
			str[i++] = '\0';
	}
	return (str);
}
