/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:20:12 by llu               #+#    #+#             */
/*   Updated: 2018/08/11 17:18:19 by xwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	rush(int x, int y);
void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int x;
	int y;

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	rush(x, y);
	return (0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}	

void	draw_line(int x, char *arr)
{
	int xloc;

	xloc = 1;
	ft_putchar(arr[0]);
	if (x != 1)
	{
		while (xloc != (x - 1))
		{
			ft_putchar(arr[1]);
			xloc++;
		}
	}
	if (x > 1)
	{
		ft_putchar(arr[2]);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int yloc;

	yloc = 1;
	if (y <= 0 || x <= 0)
		return ;
	while (yloc <= y)
	{
		if (yloc == 1)
			draw_line(x, "o-o");
		else if (y > 2 && yloc < y)
			draw_line(x, "| |");
		else if (yloc == y)
			draw_line(x, "o-o");
		yloc++;
	}
}
