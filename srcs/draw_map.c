/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 03:04:47 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/23 23:07:23 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		draw_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->height_map - 1)
	{
		j = -1;
		while (++j < data->width_map - 1)
		{
			draw_line(data->map->point[i][j], data->map->point[i][j + 1], data);
			draw_line(data->map->point[i][j], data->map->point[i + 1][j], data);
		}
	}
	draw_line(data->map->point[i][0], data->map->point[i][j], data);
	draw_line(data->map->point[0][j], data->map->point[i][j], data);
}
