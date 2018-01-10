/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:34:51 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/23 23:03:21 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		init_env(t_data *data)
{
	data->x_start = 0;
	data->y_start = 0;
	data->zoom = 0;
	data->endian = 0;
	data->size_line = 0;
}

t_matrix	matrix_void(void)
{
	int			i;
	int			j;
	t_matrix	m;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			m.matrix[i][j] = 0.0;
	}
	return (m);
}

int			ft_palete(t_point p0, t_point p1)
{
	int		z;
	int		color;

	z = p0.color > p1.color ? p0.color : p1.color;
	if (z >= 0 && z < 10)
		color = 0xC0C0C0;
	else if (z >= 10 && z < 15)
		color = 0x008080;
	else if (z >= 15 && z < 30)
		color = 0x808000;
	else if (z >= 30 && z < 40)
		color = 0x008000;
	else if (z >= 40)
		color = 0x800000;
	else
		color = 0xFF0000;
	return (color);
}

void		malloc_point(t_data **data)
{
	int			i;

	if (!((*data)->m = (t_matrix*)malloc(sizeof(t_matrix))))
		error_alloc();
	if (!((*data)->map = (t_map*)malloc(sizeof(t_map))))
		error_alloc();
	if (!((*data)->map->point = (t_point**)malloc(sizeof(t_point*)
					* ((*data)->height_map))))
		error_alloc();
	i = -1;
	while (++i < (*data)->height_map)
	{
		(*data)->map->point[i] = (t_point*)malloc(sizeof(t_point)
				* ((*data)->width_map));
		if ((*data)->map->point[i] == NULL)
		{
			while (i >= 0)
			{
				free((*data)->map->point[i]);
				i--;
			}
			free((*data)->map->point);
			error_alloc();
		}
	}
}
