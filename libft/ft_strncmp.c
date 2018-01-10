/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:00:14 by kmjaku            #+#    #+#             */
/*   Updated: 2016/07/05 14:50:23 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!n)
		return (0);
	while ((s1[i] == s2[i]) && i < (n - 1) && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
