/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:15:02 by kmjaku            #+#    #+#             */
/*   Updated: 2016/12/21 21:27:49 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_white_space(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\0'))
		return (1);
	else
		return (0);
}

int				ft_count_word(char *str)
{
	int		i;
	int		nb_word;

	i = 0;
	nb_word = 0;
	while (str[i])
	{
		if ((check_white_space(str[i]) == 0) &&
				(check_white_space(str[i + 1]) == 1))
			nb_word++;
		i++;
	}
	return (nb_word);
}
