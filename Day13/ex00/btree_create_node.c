/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:13:44 by wweng             #+#    #+#             */
/*   Updated: 2018/08/09 17:15:54 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = NULL;
	node = (t_btree*)malloc(sizeof(struct node));
	if (node)
	{
		(*node).left = 0;
		(*node).right = 0;
		(*node).item = 0;
	}
	return (node);
}
