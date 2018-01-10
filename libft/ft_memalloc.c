/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:07:10 by kmjaku            #+#    #+#             */
/*   Updated: 2016/09/02 15:18:59 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*new;

	new = NULL;
	new = (unsigned char*)malloc(size);
	if (new)
	{
		i = 0;
		while (size--)
			new[i++] = 0;
	}
	return ((void*)new);
}
