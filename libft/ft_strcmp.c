/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <kmjaku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:33:14 by kmjaku            #+#    #+#             */
/*   Updated: 2016/06/06 13:31:46 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	i = 0;
	tmp_s1 = (const unsigned char *)s1;
	tmp_s2 = (const unsigned char *)s2;
	while ((tmp_s1[i] == tmp_s2[i] && tmp_s1[i] != '\0') && (tmp_s2[i] != '\0'))
		i++;
	return (tmp_s1[i] - tmp_s2[i]);
}
