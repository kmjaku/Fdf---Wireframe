/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 21:05:25 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:13:03 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr("Wrong Parameter Number\n");
		exit(1);
	}
	usage();
	if (!(data = (t_data*)malloc(sizeof(t_data))))
		error_alloc();
	init_env(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	get_point(&data, argv[1]);
	put_isometric(data);
	set_image(data);
	mlx_hook(data->win, 2, 3, key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
