/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 10:39:15 by wweng             #+#    #+#             */
/*   Updated: 2018/08/02 10:45:55 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int count;
	int	*ran;

	if (min >= max)
	{
		ran = 0;
		return (ran);
	}
	else
	{
		count = max - min;
		ran = (int*)malloc(sizeof(*ran) * count);
		i = 0;
		while (min < max)
		{
			ran[i] = min;
			min++;
			i++;
		}
	}
	return (ran);
}
