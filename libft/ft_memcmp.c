/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 13:43:17 by kmjaku            #+#    #+#             */
/*   Updated: 2016/06/03 17:39:58 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *tmp_s1;
	unsigned char *tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n > 0 && *tmp_s1 == *tmp_s2)
	{
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*tmp_s1 - *tmp_s2);
}
