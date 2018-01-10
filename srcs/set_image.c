/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 23:58:23 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:14:06 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			set_image(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->pixel = mlx_get_data_addr(data->img, &(data->bpp),
			&(data->size_line), &(data->endian));
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
