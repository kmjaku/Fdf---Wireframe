/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:41:37 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:10:08 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		calcul_one_point(t_point *p, t_matrix *m, t_data *data)
{
	t_point	q;

	p->x -= data->x_center;
	p->y -= data->y_center;
	q.x = p->x;
	q.y = p->y;
	q.z = p->z;
	q.w = p->w;
	p->x = q.x * m->matrix[0][0] + q.y * m->matrix[1][0] + q.z *
		m->matrix[2][0] + q.w * m->matrix[3][0];
	p->y = q.x * m->matrix[0][1] + q.y * m->matrix[1][1] + q.z *
		m->matrix[2][1] + q.w * m->matrix[3][1];
	p->z = q.x * m->matrix[0][2] + q.y * m->matrix[1][2] + q.z *
		m->matrix[2][2] + q.w * m->matrix[3][2];
	p->x += data->x_center;
	p->y += data->y_center;
}

void		all_points(t_data *data, t_matrix *m)
{
	int i;
	int j;

	i = -1;
	while (++i < data->height_map)
	{
		j = -1;
		while (++j < data->width_map)
			calcul_one_point(&data->map->point[i][j], m, data);
	}
	data->x_center = (data->map->point[0][0].x +
			data->map->point[data->height_map - 1][data->width_map - 1].x) / 2;
	data->y_center = (data->map->point[0][0].y +
			data->map->point[data->height_map - 1][data->width_map - 1].y) / 2;
}

void		zoom_image(t_data *data)
{
	double		i;

	i = 0;
	if (data->width_map >= 100)
	{
		i = (int)WIDTH / data->width_map;
		data->zoom = i / 2;
	}
	else
		data->zoom = (int)WIDTH / (data->height_map * data->height_map) +
			data->height_map;
}

void		isometric(t_data *data)
{
	t_point		p;
	t_point		q;
	int			i;
	int			j;

	data->x_start = (int)WIDTH / 3 + (int)WIDTH / 8;
	data->y_start = (int)HEIGHT / 4;
	zoom_image(data);
	*data->m = scale(data->zoom, data->zoom, 1);
	all_points(data, data->m);
	free(data->m);
	i = -1;
	while (++i < data->height_map)
	{
		j = -1;
		while (++j < data->width_map)
		{
			p = data->map->point[i][j];
			q.x = data->x_start + (p.x - p.y);
			q.y = data->y_start + (p.x + p.y) - p.z;
			data->map->point[i][j].x = q.x;
			data->map->point[i][j].y = q.y;
		}
	}
}

void		put_isometric(t_data *data)
{
	isometric(data);
	data->x_center = (data->map->point[0][0].x +
			data->map->point[data->height_map - 1][data->width_map - 1].x) / 2;
	data->y_center = (data->map->point[0][0].y +
			data->map->point[data->height_map - 1][data->width_map - 1].y) / 2;
}
