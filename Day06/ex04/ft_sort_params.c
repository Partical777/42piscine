/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:33:13 by wweng             #+#    #+#             */
/*   Updated: 2018/08/01 17:33:17 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int tmp[100];
void	my_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int i;
	int y;

	i = 1;
	while (argv[i] != NULL)
	{
		if (i - 1 == 0)
		{
			tmp[i - 1] = argv[i];
		}
		y = i;
		while (argv[i] > tmp[y - 1])
		{
			if(argv[i] < tmp[y + 1])
			{
				tmp[y] = argv[y];
				break;
			}
			y++
		}
		i++;
	}

	i = 1;
	while (i < sizeof(tmp))
	{
		my_putstr(argv[tmp[i]]);
		ft_char('\n');
		i++;
	}
	return (0);
}

