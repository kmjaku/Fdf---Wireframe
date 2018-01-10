/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 00:01:25 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:13:21 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_matrix	translate(double tx, double ty, double tz)
{
	t_matrix m;

	m = matrix_void();
	m.matrix[0][0] = 1;
	m.matrix[1][1] = 1;
	m.matrix[2][2] = 1;
	m.matrix[3][0] = tx;
	m.matrix[3][1] = ty;
	m.matrix[3][2] = tz;
	m.matrix[3][3] = 1.0;
	return (m);
}

t_matrix	scale(double sx, double sy, double sz)
{
	t_matrix	m;

	m = matrix_void();
	m.matrix[0][0] = sx;
	m.matrix[1][1] = sy;
	m.matrix[2][2] = sz;
	m.matrix[3][3] = 1.0;
	return (m);
}

t_matrix	rotate_x(double x_)
{
	t_matrix	m;

	m = matrix_void();
	m.matrix[0][0] = 1.0;
	m.matrix[1][1] = cos(x_);
	m.matrix[1][2] = sin(x_);
	m.matrix[2][1] = -sin(x_);
	m.matrix[2][2] = cos(x_);
	m.matrix[3][3] = 1.0;
	return (m);
}

t_matrix	rotate_y(double y_)
{
	t_matrix	m;

	m = matrix_void();
	m.matrix[0][0] = cos(y_);
	m.matrix[0][2] = -sin(y_);
	m.matrix[1][1] = 1.0;
	m.matrix[2][0] = sin(y_);
	m.matrix[2][2] = cos(y_);
	m.matrix[3][3] = 1.0;
	return (m);
}

t_matrix	rotate_z(double z_)
{
	t_matrix	m;

	m = matrix_void();
	m.matrix[0][0] = cos(z_);
	m.matrix[0][1] = sin(z_);
	m.matrix[1][0] = -sin(z_);
	m.matrix[1][1] = cos(z_);
	m.matrix[2][2] = 1.0;
	m.matrix[3][3] = 1.0;
	return (m);
}
