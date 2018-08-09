/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:34:29 by wweng             #+#    #+#             */
/*   Updated: 2018/08/08 19:42:35 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
	{
		return (NULL);
	}
	(*tmp).data = data;
	(*tmp).next = NULL;
	return (tmp);
}
