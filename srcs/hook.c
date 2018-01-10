/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:46:18 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:12:44 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		move_right_left(int key, t_data *data)
{
	if (key == RIGHT)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		data->x_start = 10.0;
		*data->m = translate(data->x_start, 0, 0);
		all_points(data, data->m);
		free(data->m);
	}
	if (key == LEFT)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		data->x_start = -10.0;
		*data->m = translate(data->x_start, 0, 0);
		all_points(data, data->m);
		free(data->m);
	}
}

void		move_up_down(int key, t_data *data)
{
	if (key == UP)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		data->y_start = 10;
		*data->m = translate(0, data->y_start, 0);
		all_points(data, data->m);
		free(data->m);
	}
	if (key == DOWN)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		data->y_start = -10;
		*data->m = translate(0, data->y_start, 0);
		all_points(data, data->m);
		free(data->m);
	}
}

void		zoom_up_down(int key, t_data *data)
{
	if (key == ZOOM_UP && data->zoom < 100)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		data->zoom = 1.1;
		*data->m = scale(data->zoom, data->zoom, 1);
		all_points(data, data->m);
		free(data->m);
	}
	if (key == ZOOM_DOWN && data->zoom > 0)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		data->zoom = 1 / 1.1;
		*data->m = scale(data->zoom, data->zoom, 1);
		all_points(data, data->m);
		free(data->m);
	}
}

void		event_rotate_x(int key, t_data *data)
{
	if (key == R_X_P)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		*data->m = rotate_x(M_PI / 48.0);
		all_points(data, data->m);
		free(data->m);
	}
	if (key == R_X_N)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		*data->m = rotate_x(-M_PI / 48.0);
		all_points(data, data->m);
		free(data->m);
	}
}

void		event_rotate_y(int key, t_data *data)
{
	if (key == R_Y_P)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		*data->m = rotate_y(M_PI / 48.0);
		all_points(data, data->m);
		free(data->m);
	}
	if (key == R_Y_N)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		*data->m = rotate_y(-M_PI / 48.0);
		all_points(data, data->m);
		free(data->m);
	}
}
