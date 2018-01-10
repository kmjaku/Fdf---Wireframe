/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmjaku <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:48:08 by kmjaku            #+#    #+#             */
/*   Updated: 2016/07/05 14:47:20 by kmjaku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->next = NULL;
	if (content)
	{
		new->content = ft_memmove(ft_memalloc(content_size), content,
				content_size);
		new->content_size = content_size;
	}
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	return (new);
}
