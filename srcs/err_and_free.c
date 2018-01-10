/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:59:02 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:12:33 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(-1);
}

void	error_alloc(void)
{
	ft_putstr("malloc has failed.\n");
	exit(1);
}

int		get_col_nb(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
		tab = NULL;
	}
}

void	usage(void)
{
	ft_putstr("Usage of FDF :\n\n");
	ft_putstr("zoom in -> press '+'\n");
	ft_putstr("zoom out -> press '-'\n");
	ft_putstr("rotate X negative -> press '1'\n");
	ft_putstr("rotate X positive -> press '2'\n");
	ft_putstr("rotate Y negative -> press '4'\n");
	ft_putstr("rotate Y positive -> press '5'\n");
	ft_putstr("rotate Z negative -> press '7'\n");
	ft_putstr("rotate Z positive -> press '8'\n");
	ft_putstr("to exit program -> press 'esc'\n");
}
