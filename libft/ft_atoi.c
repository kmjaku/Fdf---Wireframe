/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:47:21 by kmjaku            #+#    #+#             */
/*   Updated: 2017/02/23 22:03:43 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		v;
	char	negative;

	v = 0;
	negative = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
		v = (v * 10) - (*str++ - '0');
	if (!negative)
		v = -v;
	return (v);
}
