/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:22:46 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/23 23:03:11 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		event_rotate_z(int key, t_data *data)
{
	if (key == R_Z_P)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		*(data)->m = rotate_z(M_PI / 48.0);
		all_points(data, data->m);
		free(data->m);
	}
	if (key == R_Z_N)
	{
		if (!(data->m = (t_matrix*)malloc(sizeof(t_matrix))))
			error_alloc();
		*(data->m) = rotate_z(-M_PI / 48.0);
		all_points(data, data->m);
		free(data->m);
	}
}

void		event_esc(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		ft_putstr("Exit Program\n");
		exit(1);
	}
}

int			key_hook(int key, t_data *data)
{
	move_right_left(key, data);
	move_up_down(key, data);
	zoom_up_down(key, data);
	event_rotate_x(key, data);
	event_rotate_y(key, data);
	event_rotate_z(key, data);
	event_esc(key, data);
	set_image(data);
	return (0);
}
