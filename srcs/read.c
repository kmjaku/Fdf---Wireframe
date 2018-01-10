/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 00:30:30 by kmjaku            #+#    #+#             */
/*   Updated: 2017/03/28 00:13:51 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		check_valid_char(char *file)
{
	char	*ptr;
	int		i;

	ptr = file;
	i = -1;
	while (ptr[++i])
		if (!ft_isdigit(ptr[i]) && ptr[i] != ' ' && ptr[i] != '-')
			return (0);
	return (1);
}

static void		get_col(t_data *data, char *file)
{
	char	*line;
	char	**tab;

	if ((data->fd = open(file, O_RDONLY)) < 0)
		error_exit("failed to open file\n");
	while (get_next_line(data->fd, &line))
		if (ft_strchr(line, '\n'))
			break ;
	tab = ft_strsplit(line, ' ');
	data->width_map = get_col_nb(tab);
	ft_strdel(&line);
	ft_strdel(tab);
	close(data->fd) == -1 ? error_exit("failed to close file\n") : 0;
}

static void		get_nb_line(t_data *data, char *file)
{
	char	*line;
	int		nb_l;

	if (!(data->fd = open(file, O_RDONLY)))
		error_exit("failed to open file\n");
	nb_l = 0;
	while (get_next_line(data->fd, &line))
	{
		if (!check_valid_char(line))
			error_exit("bad caracter in file\n");
		ft_strdel(&line);
		nb_l++;
	}
	data->height_map = nb_l;
	if (data->height_map == 0 && data->width_map == 0)
		error_exit("empty file\n");
	close(data->fd) == -1 ? error_exit("failed to close file\n") : 0;
}

static void		check_all(t_data *data, char *file)
{
	char	**tab;
	char	*line;
	int		i;

	get_nb_line(data, file);
	get_col(data, file);
	malloc_point(&data);
	if (!(data->fd = open(file, O_RDONLY)))
		error_exit("failed to open file\n");
	while (get_next_line(data->fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		if (data->width_map != (i = get_col_nb(tab)))
			error_exit("wrong column number\n");
		ft_strdel(&line);
		ft_strdel(tab);
	}
	close(data->fd) == -1 ? error_exit("failed to close file\n") : 0;
}

void			get_point(t_data **d, char *file)
{
	char		*line;
	int			i;
	int			nb_l;

	check_all(*d, file);
	if (((*d)->fd = open(file, O_RDONLY)) < 0)
		error_exit("file open failed\n");
	nb_l = 0;
	while ((get_next_line((*d)->fd, &line)) > 0)
	{
		(*d)->g_map = ft_strsplit(line, ' ');
		i = -1;
		while ((*d)->g_map[++i])
		{
			(*d)->map->point[nb_l][i].x = i;
			(*d)->map->point[nb_l][i].y = nb_l;
			(*d)->map->point[nb_l][i].z = ft_atoi((*d)->g_map[i]);
			(*d)->map->point[nb_l][i].w = 1;
			(*d)->map->point[nb_l][i].color = ft_atoi((*d)->g_map[i]) > 0 ?
				ft_atoi((*d)->g_map[i]) : -1 * ft_atoi((*d)->g_map[i]);
		}
		ft_strdel(&line);
		nb_l++;
	}
	close((*d)->fd) == -1 ? error_exit("failed to close file\n") : 0;
}
