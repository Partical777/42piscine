/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 12:21:26 by wweng             #+#    #+#             */
/*   Updated: 2018/08/03 12:27:15 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	ft_active_bits(int value)
{
	int ar[3];
	int i;
	int sum;

	i = 0;
	ar[0] = value % 16;
	ar[1] = value / 16;
	ar[2] = value / 256;
	while (i < 3)
	{
		int tmp;

		tmp = 0;
		if (ar[i] >= 8)
		{
			tmp += 1000;
			ar[i] -= 8;
		}
		if (ar[i] >= 4)
		{
			tmp += 100;
			ar[i] -= 4;
		}
		if (ar[i] >= 2)
		{
			tmp += 10;
			ar[i] -= 2;
		}
		if (ar[i] >= 1)
		{
			tmp += 1;
			ar[i] -= 1;
		}
		if (i > 0)
		{
			tmp = tmp * (1000 ^ i);
		}
		sum += tmp;
	}
	return (sum);
}
