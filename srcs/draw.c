/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 02:18:01 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/24 23:01:57 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		info_bres(t_data *data, t_point *p0, t_point *p1)
{
	data->dx = fabs(p0->x - p1->x);
	data->ternx = p0->x < p1->x ? 1 : -1;
	data->dy = fabs(p0->y - p1->y);
	data->terny = p0->y < p1->y ? 1 : -1;
	data->flag = (data->dx > data->dy ? data->dx : -data->dy) * 0.5;
}

static int		valid_point(t_point *p1)
{
	if (!(p1->x > WIDTH + 100 || p1->x <= 0 ||
				p1->y > HEIGHT + 100 || p1->y <= 0))
		return (1);
	else
		return (0);
}

static void		set_pixel(int x, int y, int color, t_data *data)
{
	int				i;
	unsigned int	ucolor;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (y * data->size_line) + (x * data->bpp / 8);
		ucolor = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->pixel + i, &ucolor, 3);
	}
}

static void		draw_bres(t_point p0, t_point p1, t_data *data)
{
	double	val;
	int		booll;

	booll = 1;
	while (booll == 1 && !((int)p0.x == (int)p1.x && (int)p0.y == (int)p1.y))
	{
		if (valid_point(&p0) == 1)
			set_pixel((int)p0.x, (int)p0.y, ft_palete(p0, p1), data);
		val = data->flag;
		booll = 0;
		if (val > -data->dx && (int)p0.x != (int)p1.x)
		{
			data->flag -= data->dy;
			p0.x += data->ternx;
			booll = 1;
		}
		if (val < data->dy && (int)p0.y != (int)p1.y)
		{
			data->flag += data->dx;
			p0.y += data->terny;
			booll = 1;
		}
	}
}

void			draw_line(t_point p0, t_point p1, t_data *data)
{
	if (!valid_point(&p0) && !valid_point(&p1))
		return ;
	info_bres(data, &p0, &p1);
	draw_bres(p0, p1, data);
}
