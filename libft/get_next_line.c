/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 18:06:54 by kmjaku            #+#    #+#             */
/*   Updated: 2016/12/09 19:02:09 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		other_test(char **line, char *buff, int ret, char *ptr)
{
	int				i;
	static char		*str;

	str = (!str) ? (char*)ft_memalloc(1) : str;
	ptr = ft_strjoin(str, buff);
	free(str);
	str = ptr;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
	{
		*line = ft_strndup(str, i);
		ptr = ft_strdup(str + i + 1);
		free(str);
		str = ptr;
		return (1);
	}
	if (str[i] == '\0' && ret < BUFF_SIZE && i != 0)
	{
		*line = ft_strdup(str);
		ft_bzero(str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*ptr;

	ptr = NULL;
	if ((!line) || (fd < 0))
		return (-1);
	if (fd >= 0)
	{
		ret = 1;
		while (ret != 0)
		{
			ret = read(fd, buff, BUFF_SIZE);
			if (ret < 0)
				return (-1);
			buff[ret] = '\0';
			if (other_test(line, buff, ret, ptr))
				return (1);
		}
	}
	return (0);
}
